
#include "jbuse.h"

/**
 * free structure with a reference to fuse.FuseFS java class and cached field & method IDs
 */
void free_jclass_org_opendedup_buse_driver_BUSE(JNIEnv *env, jclass_org_opendedup_buse_driver_BUSE * org_opendedup_buse_driver_BUSE)
{
   if (org_opendedup_buse_driver_BUSE->class != NULL)
      (*env)->DeleteGlobalRef(env, org_opendedup_buse_driver_BUSE->class);

   free(org_opendedup_buse_driver_BUSE);
}

/**
 * alloc structure with a reference to fuse.FuseFS java class and cached field & method IDs
 */
jclass_org_opendedup_buse_driver_BUSE *alloc_jclass_org_opendedup_buse_driver_BUSE(JNIEnv *env)
{
   jclass class;

   jclass_org_opendedup_buse_driver_BUSE * org_opendedup_buse_driver_BUSE = (jclass_org_opendedup_buse_driver_BUSE*)calloc(1, sizeof(jclass_org_opendedup_buse_driver_BUSE));
   if (org_opendedup_buse_driver_BUSE == NULL)
   {
      WARN("Can't allocate structure jclass_org_opendedup_buse_driver_BUSE");
      return NULL;
   }

   while (1)
   {
      class = (*env)->FindClass(env, "org/opendedup/buse/driver/BUSE");
      if ((*env)->ExceptionCheck(env)) break;

      org_opendedup_buse_driver_BUSE->class = (*env)->NewGlobalRef(env, class);
      if ((*env)->ExceptionCheck(env)) break;

      // obtain instance method IDs
      org_opendedup_buse_driver_BUSE->method.write__Ljava_nio_ByteBuffer_IJ = (*env)->GetMethodID(env, org_opendedup_buse_driver_BUSE->class, "write", "(Ljava/nio/ByteBuffer;IJ)I");
      if ((*env)->ExceptionCheck(env)) break;
      org_opendedup_buse_driver_BUSE->method.read__Ljava_nio_ByteBuffer_IJ = (*env)->GetMethodID(env, org_opendedup_buse_driver_BUSE->class, "read", "(Ljava/nio/ByteBuffer;IJ)I");
      if ((*env)->ExceptionCheck(env)) break;
      org_opendedup_buse_driver_BUSE->method.flush = (*env)->GetMethodID(env, org_opendedup_buse_driver_BUSE->class, "flush", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      org_opendedup_buse_driver_BUSE->method.trim__JI = (*env)->GetMethodID(env, org_opendedup_buse_driver_BUSE->class, "trim", "(JI)I");
      if ((*env)->ExceptionCheck(env)) break;
      org_opendedup_buse_driver_BUSE->method.disconnect = (*env)->GetMethodID(env, org_opendedup_buse_driver_BUSE->class, "disconnect", "()V");
      if ((*env)->ExceptionCheck(env)) break;
      return org_opendedup_buse_driver_BUSE;
   }

   // error handler
   (*env)->ExceptionDescribe(env);
   (*env)->ExceptionClear(env);
   free_jclass_org_opendedup_buse_driver_BUSE(env, org_opendedup_buse_driver_BUSE);
   return NULL;
}

/**
 * free structure with a reference to java.nio.ByteBuffer java class and cached field & method IDs
 */
void free_jclass_java_nio_ByteBuffer(JNIEnv *env, jclass_java_nio_ByteBuffer *java_nio_ByteBuffer)
{
   if (java_nio_ByteBuffer->class != NULL)
      (*env)->DeleteGlobalRef(env, java_nio_ByteBuffer->class);

   free(java_nio_ByteBuffer);
}

/**
 * alloc structure with a reference to java.nio.ByteBuffer java class and cached field & method IDs
 */
jclass_java_nio_ByteBuffer *alloc_jclass_java_nio_ByteBuffer(JNIEnv *env)
{
   jclass class;

   jclass_java_nio_ByteBuffer *java_nio_ByteBuffer = (jclass_java_nio_ByteBuffer*)calloc(1, sizeof(jclass_java_nio_ByteBuffer));
   if (java_nio_ByteBuffer == NULL)
   {
      WARN("Can't allocate structure jclass_java_nio_ByteBuffer");
      return NULL;
   }

   while (1)
   {
      class = (*env)->FindClass(env, "java/nio/ByteBuffer");
      if ((*env)->ExceptionCheck(env)) break;

      java_nio_ByteBuffer->class = (*env)->NewGlobalRef(env, class);
      if ((*env)->ExceptionCheck(env)) break;

      // obtain static method IDs
      java_nio_ByteBuffer->static_method.wrap___B = (*env)->GetStaticMethodID(env, java_nio_ByteBuffer->class, "wrap", "([B)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->static_method.wrap___BII = (*env)->GetStaticMethodID(env, java_nio_ByteBuffer->class, "wrap", "([BII)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->static_method.allocate__I = (*env)->GetStaticMethodID(env, java_nio_ByteBuffer->class, "allocate", "(I)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->static_method.allocateDirect__I = (*env)->GetStaticMethodID(env, java_nio_ByteBuffer->class, "allocateDirect", "(I)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;

      // obtain instance method IDs
      java_nio_ByteBuffer->method.get = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "get", "()B");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.get___B = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "get", "([B)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.get___BII = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "get", "([BII)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.get__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "get", "(I)B");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.put__Ljava_nio_ByteBuffer_ = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "put", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.put___B = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "put", "([B)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.put__B = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "put", "(B)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.put__IB = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "put", "(IB)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.put___BII = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "put", "([BII)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.equals__Ljava_lang_Object_ = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "equals", "(Ljava/lang/Object;)Z");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.toString = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "toString", "()Ljava/lang/String;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.hashCode = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "hashCode", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.compareTo__Ljava_lang_Object_ = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "compareTo", "(Ljava/lang/Object;)I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.compareTo__Ljava_nio_ByteBuffer_ = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "compareTo", "(Ljava/nio/ByteBuffer;)I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getShort__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getShort", "(I)S");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getShort = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getShort", "()S");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putShort__IS = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putShort", "(IS)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putShort__S = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putShort", "(S)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getChar = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getChar", "()C");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getChar__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getChar", "(I)C");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putChar__IC = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putChar", "(IC)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putChar__C = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putChar", "(C)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getInt = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getInt", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getInt__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getInt", "(I)I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putInt__II = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putInt", "(II)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putInt__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putInt", "(I)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getLong__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getLong", "(I)J");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getLong = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getLong", "()J");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putLong__J = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putLong", "(J)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putLong__IJ = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putLong", "(IJ)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getFloat = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getFloat", "()F");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getFloat__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getFloat", "(I)F");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putFloat__F = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putFloat", "(F)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putFloat__IF = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putFloat", "(IF)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getDouble = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getDouble", "()D");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getDouble__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getDouble", "(I)D");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putDouble__ID = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putDouble", "(ID)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.putDouble__D = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "putDouble", "(D)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.isDirect = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "isDirect", "()Z");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.hasArray = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "hasArray", "()Z");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.array = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "array", "()[B");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.array = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "array", "()Ljava/lang/Object;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.arrayOffset = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "arrayOffset", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.duplicate = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "duplicate", "()Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.slice = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "slice", "()Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asReadOnlyBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asReadOnlyBuffer", "()Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.compact = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "compact", "()Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.order__Ljava_nio_ByteOrder_ = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "order", "(Ljava/nio/ByteOrder;)Ljava/nio/ByteBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.order = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "order", "()Ljava/nio/ByteOrder;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asCharBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asCharBuffer", "()Ljava/nio/CharBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asShortBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asShortBuffer", "()Ljava/nio/ShortBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asIntBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asIntBuffer", "()Ljava/nio/IntBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asLongBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asLongBuffer", "()Ljava/nio/LongBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asFloatBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asFloatBuffer", "()Ljava/nio/FloatBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.asDoubleBuffer = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "asDoubleBuffer", "()Ljava/nio/DoubleBuffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.limit = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "limit", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.limit__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "limit", "(I)Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.clear = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "clear", "()Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.remaining = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "remaining", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.position__I = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "position", "(I)Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.position = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "position", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.capacity = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "capacity", "()I");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.mark = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "mark", "()Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.reset = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "reset", "()Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.flip = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "flip", "()Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.rewind = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "rewind", "()Ljava/nio/Buffer;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.hasRemaining = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "hasRemaining", "()Z");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.isReadOnly = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "isReadOnly", "()Z");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.wait = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "wait", "()V");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.wait__J = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "wait", "(J)V");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.wait__JI = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "wait", "(JI)V");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.getClass = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "getClass", "()Ljava/lang/Class;");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.notify = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "notify", "()V");
      if ((*env)->ExceptionCheck(env)) break;
      java_nio_ByteBuffer->method.notifyAll = (*env)->GetMethodID(env, java_nio_ByteBuffer->class, "notifyAll", "()V");
      if ((*env)->ExceptionCheck(env)) break;

      // we're done
      return java_nio_ByteBuffer;
   }

   // error handler
   (*env)->ExceptionDescribe(env);
   (*env)->ExceptionClear(env);
   free_jclass_java_nio_ByteBuffer(env, java_nio_ByteBuffer);
   return NULL;
}
