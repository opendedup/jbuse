#include <jni.h>
/**
 * structure with a reference to fuse.FuseFS java class and cached field & method IDs
 */
typedef struct _jclass_org_opendedup_buse_driver_BUSE
{
   // a pointer to globaly referenced Java class
   jclass class;

   // cached instance method IDs
   struct
   {
      jmethodID write__Ljava_nio_ByteBuffer_IJ;
      jmethodID read__Ljava_nio_ByteBuffer_IJ;
      jmethodID flush;
      jmethodID trim__JI;
      jmethodID disconnect;

   } method;

} jclass_org_opendedup_buse_driver_BUSE;

// free structure
void free_jclass_org_opendedup_buse_driver_BUSE(JNIEnv *env, jclass_org_opendedup_buse_driver_BUSE * org_opendedup_buse_driver_BUSE);

// alloc structure
jclass_org_opendedup_buse_driver_BUSE *alloc_jclass_org_opendedup_buse_driver_BUSE(JNIEnv *env);


/**
 * structure with a reference to java.nio.ByteBuffer java class and cached field & method IDs
 */
typedef struct _jclass_java_nio_ByteBuffer
{
   // a pointer to globaly referenced Java class
   jclass class;

   // cached static method IDs
   struct
   {
      jmethodID wrap___B;
      jmethodID wrap___BII;
      jmethodID allocate__I;
      jmethodID allocateDirect__I;

   } static_method;

   // cached instance method IDs
   struct
   {
      jmethodID get;
      jmethodID get___B;
      jmethodID get___BII;
      jmethodID get__I;
      jmethodID put__Ljava_nio_ByteBuffer_;
      jmethodID put___B;
      jmethodID put__B;
      jmethodID put__IB;
      jmethodID put___BII;
      jmethodID equals__Ljava_lang_Object_;
      jmethodID toString;
      jmethodID hashCode;
      jmethodID compareTo__Ljava_lang_Object_;
      jmethodID compareTo__Ljava_nio_ByteBuffer_;
      jmethodID getShort__I;
      jmethodID getShort;
      jmethodID putShort__IS;
      jmethodID putShort__S;
      jmethodID getChar;
      jmethodID getChar__I;
      jmethodID putChar__IC;
      jmethodID putChar__C;
      jmethodID getInt;
      jmethodID getInt__I;
      jmethodID putInt__II;
      jmethodID putInt__I;
      jmethodID getLong__I;
      jmethodID getLong;
      jmethodID putLong__J;
      jmethodID putLong__IJ;
      jmethodID getFloat;
      jmethodID getFloat__I;
      jmethodID putFloat__F;
      jmethodID putFloat__IF;
      jmethodID getDouble;
      jmethodID getDouble__I;
      jmethodID putDouble__ID;
      jmethodID putDouble__D;
      jmethodID isDirect;
      jmethodID hasArray;
      //jmethodID array;
      jmethodID array;
      jmethodID arrayOffset;
      jmethodID duplicate;
      jmethodID slice;
      jmethodID asReadOnlyBuffer;
      jmethodID compact;
      jmethodID order__Ljava_nio_ByteOrder_;
      jmethodID order;
      jmethodID asCharBuffer;
      jmethodID asShortBuffer;
      jmethodID asIntBuffer;
      jmethodID asLongBuffer;
      jmethodID asFloatBuffer;
      jmethodID asDoubleBuffer;
      jmethodID limit;
      jmethodID limit__I;
      jmethodID clear;
      jmethodID remaining;
      jmethodID position__I;
      jmethodID position;
      jmethodID capacity;
      jmethodID mark;
      jmethodID reset;
      jmethodID flip;
      jmethodID rewind;
      jmethodID hasRemaining;
      jmethodID isReadOnly;
      jmethodID wait;
      jmethodID wait__J;
      jmethodID wait__JI;
      jmethodID getClass;
      jmethodID notify;
      jmethodID notifyAll;

   } method;

} jclass_java_nio_ByteBuffer;

// free structure
void free_jclass_java_nio_ByteBuffer(JNIEnv *env, jclass_java_nio_ByteBuffer *java_nio_ByteBuffer);

// alloc structure
jclass_java_nio_ByteBuffer *alloc_jclass_java_nio_ByteBuffer(JNIEnv *env);

