
#include <cstdlib>
#include "miku_lib_common_Native_NativeUtil.h"



JNIEXPORT void JNICALL Java_miku_lib_common_Native_NativeUtil_Kill
        (JNIEnv *env, jclass cls, jobject entity){
    jclass entity_class = (*env).FindClass("net/minecraft/entity/Entity");
    jclass entity_living_base_class = (*env).FindClass("net/minecraft/entity/EntityLivingBase");
    if(entity_class == nullptr) {
        printf("Error: can't get Entity class!");
        return;
    }
    if(entity_living_base_class == nullptr) {
        printf("Error: can't get EntityLivingBase class!");
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
            jobject manager = (*env).GetObjectField(entity,dataManager);
            if(manager != nullptr){
                jfieldID FLAGS_ID = (*env).GetStaticFieldID(entity_class, "field_184240_ax",
                                                            "Lnet/minecraft/network/datasync/DataParameter;");
                if (FLAGS_ID != nullptr) {
                    jclass EntityDataManager = (*env).FindClass("net/minecraft/network/datasync/EntityDataManager");
                    if (EntityDataManager != nullptr) {

                        jmethodID get = (*env).GetMethodID(EntityDataManager, "func_187225_a",
                                                           "<T:Ljava/lang/Object;>(Lnet/minecraft/network/datasync/DataParameter<TT;>;)TT;");
                        if (get != nullptr) {
                            jobject FLAGS = (*env).GetStaticObjectField(entity_class, FLAGS_ID);
                            if (FLAGS != nullptr) {
                                jbyte b0 = (*env).CallByteMethod(manager,get,FLAGS);
                                jmethodID set = (*env).GetMethodID(EntityDataManager,"func_187227_b","<T:Ljava/lang/Object;>(Lnet/minecraft/network/datasync/DataParameter<TT;>;TT;)V");
                                if(set != nullptr){
                                    (*env).CallVoidMethod(manager,set,(b0 | 1 << 5));
                                    (*env).CallVoidMethod(manager,set,(b0 & ~(1)));
                                }
                            }
                        }
                    }
                }
            }
        }
        jfieldID velocityChanged = (*env).GetFieldID(entity_class,"field_70133_I","Z");
        if(velocityChanged != nullptr){
            (*env).SetBooleanField(entity,velocityChanged, true);
        }
        if((*env).IsInstanceOf(entity,entity_living_base_class)){
            jfieldID limbSwingAmount = (*env).GetFieldID(entity_living_base_class,"field_70721_aZ","F");
            if(limbSwingAmount != nullptr){
                (*env).SetFloatField(entity,limbSwingAmount,1.5F);
            }
            jfieldID idleTime = (*env).GetFieldID(entity_living_base_class,"field_70708_bq","I");
            if(idleTime != nullptr){
                (*env).SetIntField(entity,idleTime,0);
            }

        }
    }
}

JNIEXPORT jint JNICALL Java_miku_lib_common_Native_NativeUtil_TEST
        (JNIEnv *env, jclass cls){
    printf("Hello World!");
    system("echo Hello World!");
    return 39;
}