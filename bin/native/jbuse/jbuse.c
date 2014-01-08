/*
 * busexmp - example memory-based block device using BUSE
 * Copyright (C) 2013 Adam Cozzette
 *
 * This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include "buse.h"
#include "jbuse.h"
// JVM allocation/deallocation

static JavaVM *vm;
static JNIEnv *mainEnv;

jclass_java_nio_ByteBuffer *ByteBuffer;
jclass_org_opendedup_buse_driver_BUSE *BUSE;

jobject threadGroup;


int retain_buseDEV(JNIEnv *env, jobject util)
{


   if ((*env)->ExceptionCheck(env))
   {
      (*env)->ExceptionDescribe(env);
      return 0;
   }

   return 1;
}


  void free_threadGroup(JNIEnv *env)
{
   if (threadGroup != NULL) { (*env)->DeleteGlobalRef(env, threadGroup); threadGroup = NULL; }
}


  int retain_threadGroup(JNIEnv *env, jobject util)
{
   threadGroup = (*env)->NewGlobalRef(env, util);

   if ((*env)->ExceptionCheck(env))
   {
      (*env)->ExceptionDescribe(env);
      return 0;
   }

   return 1;
}


  void free_classes(JNIEnv *env)
{
   if (ByteBuffer != NULL)      { free_jclass_java_nio_ByteBuffer(env, ByteBuffer);       ByteBuffer = NULL; }
   if (BUSE != NULL)          { free_jclass_org_opendedup_buse_driver_BUSE(env, BUSE);                   BUSE = NULL; }
}


  int alloc_classes(JNIEnv *env)
{
   while (1)
   {
      if (!(ByteBuffer      = alloc_jclass_java_nio_ByteBuffer(env))) break;
      if (!(BUSE          = alloc_jclass_org_opendedup_buse_driver_BUSE(env))) break;

      return 1;
   }

   // error handler

   if ((*env)->ExceptionCheck(env))
   {
      (*env)->ExceptionDescribe(env);
   }

   free_classes(env);

   return 0;
}


  void free_JVM(JNIEnv *env)
{
   if (vm != NULL)
   {
      (*vm)->DestroyJavaVM(vm);
      vm = NULL;
      mainEnv = NULL;
   }
}


//
// attaching/detachnig current thread to/from JVM

  JNIEnv *get_env()
{
   JNIEnv *env;
   JavaVMAttachArgs args;

   args.version = JNI_VERSION_1_6;
   args.name = NULL;
   args.group = threadGroup;

   // a GCJ 4.0 bug workarround (supplied by Alexander Boström <abo@stacken.kth.se>)
   if ((*vm)->GetEnv(vm, (void**)&env, args.version) == JNI_OK)
      return env;

   TRACE("will attach thread");

   // attach thread as daemon thread so that JVM can exit after unmounting the fuseFS
   (*vm)->AttachCurrentThreadAsDaemon(vm, (void**)&env, (void*)&args);

   TRACE("did attach thread to env: %p", env);

   return env;
}

  void release_env(JNIEnv *env)
{
   if (env == mainEnv)
   {
      //TRACE("will NOT detach main thread from env: %p", env);
   }
   else
   {
      //TRACE("will NOT detach thread from env: %p", env);

      // Currently native threads are attached to JVM as daemon threads so we don't need to
      // detach them at return from a Java method call. It is in fact beter not to detach them
      // since then every new Java call would need to atach new Java Thread until max. number of
      // Java threads is exhausted.
      //
      //TRACE("will detach thread from env: %p", env);
      //(*vm)->DetachCurrentThread(vm);
      //TRACE("did detach thread");
   }
}

  jint exception_check_jerrno(JNIEnv *env, jint *jerrno)
{
   if ((*env)->ExceptionCheck(env))
   {
      (*env)->ExceptionDescribe(env);
      (*env)->ExceptionClear(env);
      if (*jerrno == 0)
      {
         *jerrno = EFAULT;
      }
   }

   return *jerrno;
}

  int bread(void *buf, u_int32_t len, u_int64_t offset, void *userdata)
{

TRACE("R - off=%lu, len=%u\n", offset, len);	
   JNIEnv *env = get_env();
   jobject jBuf = NULL;
   jint jerrno = 0;
   jint nread = 0;
    
   		TRACE("R - off=%lu, len=%u\n", offset, len);	
   while (1)
   {
      jBuf = (*env)->NewDirectByteBuffer(env, (void *)buf, (jlong)len);
      if (exception_check_jerrno(env, &jerrno)) break;
      jerrno = (*env)->CallIntMethod(env, (jobject)userdata, BUSE->method.read__Ljava_nio_ByteBuffer_IJ, jBuf, (jint)len,(jlong)offset);
      exception_check_jerrno(env, &jerrno);
       
   		TRACE("R - nread=%u\n", len);
      break;
   }

   // cleanup

   if (jBuf != NULL) (*env)->DeleteLocalRef(env, jBuf);

   release_env(env);
   
   return jerrno? -jerrno : 0;
}

  int bwrite(const void *buf, u_int32_t len, u_int64_t offset, void *userdata)
{
	TRACE("W - off=%lu, len=%u\n", offset, len);	
   JNIEnv *env = get_env();
   jobject jBuf = NULL;
   jint nwriten = 0;
   jint jerrno = 0;

   
   while (1)
   {
      jBuf = (*env)->NewDirectByteBuffer(env, (void *)buf, (jlong)len);
      if (exception_check_jerrno(env, &jerrno)) break;
      jerrno = (*env)->CallIntMethod(env, (jobject)userdata, BUSE->method.write__Ljava_nio_ByteBuffer_IJ, jBuf, (jint)len,(jlong)offset);
      exception_check_jerrno(env, &jerrno);
   		TRACE("W - nwrite=%u\n", len);
      break;
   }

   // cleanup

   if (jBuf != NULL) {
 	(*env)->DeleteLocalRef(env, jBuf);
  }  
   release_env(env);
    
   		TRACE("W - %lu, %u\n", offset, len);	
   return jerrno? -jerrno : 0;
}

  void bdisc(void *userdata)
{
   JNIEnv *env = get_env();
  		TRACE("Received a disconnect request.\n");
  (*env)->CallIntMethod(env, (jobject)userdata, BUSE->method.disconnect);
  release_env(env);
}

  int bflush(void *userdata)
{
jint jerrno = 0;
JNIEnv *env = get_env();
while(1) {
   
  		TRACE("Received a flush request.\n");
  jerrno = (*env)->CallIntMethod(env, (jobject)userdata, BUSE->method.flush);
  exception_check_jerrno(env, &jerrno);
  break;
  }
  release_env(env);
  return jerrno? -jerrno : 0;
}

int btrim(u_int64_t from, u_int32_t len, void *userdata)
{
   jint jerrno = 0;
   JNIEnv *env = get_env();
   while(1) {
  		TRACE("T - %lu, %u\n", from, len);
  jerrno = (*env)->CallIntMethod(env, (jobject)userdata, BUSE->method.trim__JI,(jlong)from,(jint)len);
  exception_check_jerrno(env, &jerrno);
  break;
  }
  release_env(env);
  return jerrno? -jerrno : 0;
}

//
// JNI boot-up

/*
 * Class:     fuse_FuseMount
 * Method:    mount
 * Signature: ([Ljava/lang/String;J;Lorg/opendedup/buse/driver/BUSE;Ljava/lang/ThreadGroup;)V
 */
JNIEXPORT jint JNICALL Java_org_opendedup_buse_driver_BUSEMkDev_mkdev(JNIEnv *env, jclass class, jstring dev,jlong jsz, jint blksz, jobject jBUSE, jboolean readonly) {
	struct buse_operations aop = {
  .read = bread,
  .write = bwrite,
  .disc = bdisc,
  .flush = bflush,
  .trim = btrim,
  .blocksize=blksz,
  .readonly = readonly,
  .size = jsz
};

   
      const char *arg= (*env)->GetStringUTFChars(env,dev,0);
      char *sdev = (char *)malloc(strlen(arg) + 1);
      strcpy(sdev, arg);
      (*env)->ReleaseStringUTFChars(env,dev, arg);
      (*env)->DeleteLocalRef(env, dev);
	  jobject buseDEV = (*env)->NewGlobalRef(env, jBUSE);
      
         if (retain_buseDEV(env, jBUSE))
         {
               // main loop
               TRACE("T - %s, %"PRIu64"\n", sdev,aop.size);
               buse_main(sdev, &aop, (void *) buseDEV);
         }

         // cleanup
      if (buseDEV != NULL) { (*env)->DeleteGlobalRef(env, buseDEV); buseDEV = NULL; }   
      free(sdev);
      
   
}

JNIEXPORT void JNICALL Java_org_opendedup_buse_driver_BUSEMkDev_init(JNIEnv *env, jclass class,jobject jThreadGroup) {
	if (!((*env)->GetJavaVM(env, &vm)))
   {
   	mainEnv = env;
   	if (alloc_classes(env))
    {
   	retain_threadGroup(env, jThreadGroup);
   	}
   	}
}

JNIEXPORT void JNICALL Java_org_opendedup_buse_driver_BUSEMkDev_release(JNIEnv *env, jclass class) {
	free_threadGroup(env);
	free_classes(env);
    vm = NULL;
    mainEnv = NULL;           
}

JNIEXPORT void JNICALL Java_org_opendedup_buse_driver_BUSEMkDev_closedev (JNIEnv *env, jclass class,jstring dev) {

	const char *arg= (*env)->GetStringUTFChars(env,dev,0);
    char *sdev = (char *)malloc(strlen(arg) + 1);
    strcpy(sdev, arg);
    (*env)->ReleaseStringUTFChars(env,dev, arg);
    (*env)->DeleteLocalRef(env, dev);
    disconnectDev(sdev);
    free(sdev);
}

JNIEXPORT void JNICALL Java_org_opendedup_buse_driver_BUSEMkDev_setSize (JNIEnv *env, jclass class,jstring dev,jlong jsz) {

	const char *arg= (*env)->GetStringUTFChars(env,dev,0);
    char *sdev = (char *)malloc(strlen(arg) + 1);
    strcpy(sdev, arg);
    (*env)->ReleaseStringUTFChars(env,dev, arg);
    (*env)->DeleteLocalRef(env, dev);
    setSize(sdev,jsz);
    free(sdev);
}



