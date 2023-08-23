
#include <iostream>
#include "miku_lib_common_Native_NativeUtil.h"



JNIEXPORT void JNICALL Java_miku_lib_common_Native_NativeUtil_Kill
        (JNIEnv *env, jclass cls, jobject entity){
    jclass entity_class = (*env).FindClass("net/minecraft/entity/Entity");
    jclass entity_living_base_class = (*env).FindClass("net/minecraft/entity/EntityLivingBase");
    jclass entity_living_class = (*env).FindClass("net/minecraft/entity/EntityLiving");
    if(entity_class == nullptr) {
        std::cout << "Error: can't get Entity class!";
        return;
    }
    if(entity_living_base_class == nullptr) {
        std::cout << "Error: can't get EntityLivingBase class!";
        return;
    }
    if (entity_living_class == nullptr) {
        std::cout << "Error: can't get EntityLiving class!";
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
            jfieldID lastDamage = (*env).GetFieldID(entity_living_base_class,"field_110153_bc","I");
            if(lastDamage != nullptr){
                (*env).SetIntField(entity,lastDamage,2147483647);
            }
            jfieldID recentlyHit = (*env).GetFieldID(entity_living_base_class,"field_70718_bc","I");
            if(recentlyHit != nullptr){
                (*env).SetIntField(entity,recentlyHit,60);
            }
            jfieldID revengeTarget = (*env).GetFieldID(entity_living_base_class,"field_70755_b","Lnet/minecraft/entity/EntityLivingBase;");
            if(revengeTarget != nullptr){
                (*env).SetObjectField(entity,revengeTarget, nullptr);
            }
            jfieldID revengeTimer = (*env).GetFieldID(entity_living_base_class,"field_70756_c","I");
            if(revengeTimer != nullptr){
                (*env).SetIntField(entity,revengeTimer,0);
            }
            jfieldID activePotionsMap = (*env).GetFieldID(entity_living_base_class,"field_70713_bf","Ljava/util/Map<Lnet/minecraft/potion/Potion;Lnet/minecraft/potion/PotionEffect;>;");
            if(activePotionsMap != nullptr){
                jclass HashMap = (*env).FindClass("java/util/HashMap");
                if(HashMap != nullptr){
                    jmethodID constructor = (*env).GetMethodID(HashMap,"<init>","()V");
                    if(constructor != nullptr){
                        (*env).SetObjectField(entity,activePotionsMap,
                                              (*env).NewObject(HashMap,constructor));
                    }
                }
            }
            if(dataManager != nullptr){
                jobject manager = (*env).GetObjectField(entity,dataManager);
                if(manager != nullptr){
                    jfieldID HEALTH_ID = (*env).GetStaticFieldID(entity_living_base_class,"field_184632_c","Lnet/minecraft/network/datasync/DataParameter<Ljava/lang/Float;>;");
                    if(HEALTH_ID != nullptr){
                        jobject HEALTH = (*env).GetStaticObjectField(entity_living_base_class, HEALTH_ID);
                        if (HEALTH != nullptr) {
                            jclass EntityDataManager = (*env).FindClass("net/minecraft/network/datasync/EntityDataManager");
                            if(EntityDataManager != nullptr){
                                jmethodID set = (*env).GetMethodID(EntityDataManager,"func_187227_b","<T:Ljava/lang/Object;>(Lnet/minecraft/network/datasync/DataParameter<TT;>;TT;)V");
                                if(set != nullptr){
                                    (*env).CallVoidMethod(manager,set,HEALTH,0.0f);
                                }
                            }
                        }
                    }
                }
            }
            jfieldID attributeMap_ID = (*env).GetFieldID(entity_living_base_class,"field_110155_d","Lnet/minecraft/entity/ai/attributes/AbstractAttributeMap;");
            if(attributeMap_ID != nullptr){
                jclass AttributeMap = (*env).FindClass("net/minecraft/entity/ai/attributes/AttributeMap");
                if (AttributeMap != nullptr) {
                    jmethodID constructor = (*env).GetMethodID(AttributeMap, "<init>", "()V");
                    if (constructor != nullptr) {
                        (*env).SetObjectField(entity, attributeMap_ID,
                                              (*env).NewObject(AttributeMap, constructor));
                    }
                }
            }
            jfieldID dead = (*env).GetFieldID(entity_living_base_class, "field_70729_aU", "Z");
            if (dead != nullptr) {
                (*env).SetBooleanField(entity, dead, true);
            }
            jfieldID deathTime = (*env).GetFieldID(entity_living_base_class, "field_70725_aQ", "I");
            if (deathTime != nullptr) {
                (*env).SetIntField(entity, deathTime, 2147483647);
            }
            jfieldID attackingPlayer = (*env).GetFieldID(entity_living_base_class, "field_70717_bb",
                                                         "Lnet/minecraft/entity/player/EntityPlayer;");
            if (attackingPlayer != nullptr) {
                (*env).SetObjectField(entity, attackingPlayer, nullptr);
            }
            jfieldID lastAttackedEntity = (*env).GetFieldID(entity_living_base_class, "field_110150_bn",
                                                            "Lnet/minecraft/entity/EntityLivingBase;");
            if (lastAttackedEntity != nullptr) {
                (*env).SetObjectField(entity, lastAttackedEntity, nullptr);
            }
            jfieldID lastAttackedEntityTime = (*env).GetFieldID(entity_living_base_class, "field_142016_bo", "I");
            if (lastAttackedEntityTime != nullptr) {
                (*env).SetIntField(entity, lastAttackedEntityTime, 0);
            }
            jfieldID absorptionAmount = (*env).GetFieldID(entity_living_base_class, "field_110151_bq", "I");
            if (absorptionAmount != nullptr) {
                (*env).SetIntField(entity, absorptionAmount, 0);
            }
            jfieldID combatTracker = (*env).GetFieldID(entity_living_base_class, "field_94063_bt",
                                                       "Lnet/minecraft/util/CombatTracker;");
            if (combatTracker != nullptr) {
                jclass CombatTracker = (*env).FindClass("net/minecraft/util/CombatTracker");
                if (CombatTracker != nullptr) {
                    jmethodID constructor = (*env).GetMethodID(CombatTracker, "<init>",
                                                               "(Lnet/minecraft/entity/EntityLivingBase;)V");
                    if (constructor != nullptr) {
                        (*env).SetObjectField(entity, combatTracker,
                                              (*env).NewObject(CombatTracker, constructor, entity));
                    }
                }
            }
            if ((*env).IsInstanceOf(entity, entity_living_class)) {
                if (dataManager != nullptr) {
                    jobject manager = (*env).GetObjectField(entity, dataManager);
                    if (manager != nullptr) {
                        jfieldID AI_FLAGS_ID = (*env).GetStaticFieldID(entity_living_base_class, "field_184654_a",
                                                                       "Lnet/minecraft/network/datasync/DataParameter<Ljava/lang/Byte;>;");
                        if (AI_FLAGS_ID != nullptr) {
                            jobject AI_FLAGS = (*env).GetStaticObjectField(entity_living_base_class, AI_FLAGS_ID);
                            if (AI_FLAGS != nullptr) {
                                jclass EntityDataManager = (*env).FindClass(
                                        "net/minecraft/network/datasync/EntityDataManager");
                                if (EntityDataManager != nullptr) {
                                    jmethodID set = (*env).GetMethodID(EntityDataManager, "func_187227_b",
                                                                       "<T:Ljava/lang/Object;>(Lnet/minecraft/network/datasync/DataParameter<TT;>;TT;)V");
                                    if (set != nullptr) {
                                        (*env).CallVoidMethod(manager, set, AI_FLAGS, (jbyte) 1);
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }
}

JNIEXPORT jint JNICALL Java_miku_lib_common_Native_NativeUtil_TEST
        (JNIEnv *env, jclass cls){
    std::cout << "Hello world!\n";
    printf("Hello World!\n");
    return 39;
}