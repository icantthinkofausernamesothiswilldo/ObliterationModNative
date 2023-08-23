
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
        jfieldID isDead = (*env).GetFieldID(entity_class,"field_70128_L","Z");
        if(isDead != nullptr){
            (*env).SetBooleanField(entity,isDead, true);
        }
        jfieldID dataManager = (*env).GetFieldID(entity_class,"field_70180_af","Lnet/minecraft/network/datasync/DataParameter<Ljava/lang/Byte;>;");
        if(dataManager != nullptr){
            jfieldID FLAGS = (*env).GetStaticFieldID(entity_class,"field_184240_ax","Lnet/minecraft/network/datasync/DataParameter;");
            jclass EntityDataManager = (*env).FindClass("net/minecraft/network/datasync/EntityDataManager");
            jmethodID get = (*env).GetMethodID(EntityDataManager,"func_187225_a","<T:Ljava/lang/Object;>(Lnet/minecraft/network/datasync/DataParameter<TT;>;)TT;");
        }
    }
}

JNIEXPORT jint JNICALL Java_miku_lib_common_Native_NativeUtil_TEST
        (JNIEnv *env, jclass cls){
    printf("Hello World!");
    system("echo Hello World!");
    return 39;
}