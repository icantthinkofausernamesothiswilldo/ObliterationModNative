
#include <cstdlib>
#include "miku_lib_common_Native_NativeUtil.h"


JNIEXPORT void JNICALL Java_miku_lib_common_Native_NativeUtil_Kill
        (JNIEnv *env, jclass cls, jobject entity){
    jclass entity_class = (*env).FindClass("net/minecraft/entity/Entity");
    if(entity_class == nullptr) {
        printf("Error: can't get entity class!");
        return;
    }
    if((*env).IsInstanceOf(entity, entity_class)){
        jfieldID isInWeb = (*env).GetFieldID(entity_class, "field_70134_J", "Z");
        if(isInWeb != nullptr){
            (*env).SetBooleanField(entity, isInWeb, true);
        }
        jfieldID fire = (*env).GetFieldID(entity_class,"field_190534_ay","I");
        if(fire != nullptr){
            (*env).SetIntField(entity,fire,2147483647);
        }
        jfieldID isAddedToWorld = (*env).GetFieldID(entity_class,"isAddedToWorld","Z");
        if(isAddedToWorld != nullptr){
            (*env).SetBooleanField(entity,isAddedToWorld, false);
        }
    }
}

JNIEXPORT jint JNICALL Java_miku_lib_common_Native_NativeUtil_TEST
        (JNIEnv *env, jclass cls){
    printf("Hello World!");
    system("echo Hello World!");
    return 39;
}