
#include <iostream>
#include "miku_lib_common_Native_NativeUtil.h"



JNIEXPORT void JNICALL Java_miku_lib_common_Native_NativeUtil_Kill
        (JNIEnv *env, jclass cls, jobject entity){
    jclass Entity = (*env).FindClass("net/minecraft/entity/Entity");
    jclass EntityLivingBase = (*env).FindClass("net/minecraft/entity/EntityLivingBase");
    jclass EntityLiving = (*env).FindClass("net/minecraft/entity/EntityLiving");
    jclass EntityPlayer = (*env).FindClass("net/minecraft/entity/player/EntityPlayer");
    jclass InventoryBasic = (*env).FindClass("net/minecraft/inventory/InventoryBasic");
    jclass NonNullList = (*env).FindClass("net/minecraft/util/NonNullList");
    jclass ItemStack = (*env).FindClass("net/minecraft/item/ItemStack");
    jclass InventoryPlayer = (*env).FindClass("net/minecraft/entity/player/InventoryPlayer");
    jclass ArrayList = (*env).FindClass("java/util/ArrayList");
    jclass World = (*env).FindClass("net/minecraft/world/World");
    jclass IWorldEventListener = (*env).FindClass("net/minecraft/world/IWorldEventListener");
    jclass EntityDataManager = (*env).FindClass("net/minecraft/network/datasync/EntityDataManager");
    jclass Chunk = (*env).FindClass("net/minecraft/world/chunk/Chunk");
    jclass ClassInheritanceMultiMap = (*env).FindClass("net/minecraft/util/ClassInheritanceMultiMap");
    jclass WorldClient = (*env).FindClass("net/minecraft/client/multiplayer/WorldClient");
    jclass Minecraft = (*env).FindClass("net/minecraft/client/Minecraft");
    jclass HashSet = (*env).FindClass("java/util/HashSet");
    jobject EMPTY;
    if (ItemStack != nullptr) {
        jfieldID EMPTY_ID = (*env).GetStaticFieldID(ItemStack, "field_190927_a", "Lnet/minecraft/item/ItemStack;");
        if (EMPTY_ID != nullptr) {
            EMPTY = (*env).GetStaticObjectField(ItemStack, EMPTY_ID);
        }
    }
    if (Entity == nullptr) {
        std::cout << "Error: can't get Entity class!";
        return;
    }
    if (EntityLivingBase == nullptr) {
        std::cout << "Error: can't get EntityLivingBase class!";
        return;
    }
    if (EntityLiving == nullptr) {
        std::cout << "Error: can't get EntityLiving class!";
        return;
    }
    if (EntityPlayer == nullptr) {
        std::cout << "Error: can't get EntityPlayer class!";
        return;
    }
    if ((*env).IsInstanceOf(entity, Entity)) {
        jfieldID isInWeb = (*env).GetFieldID(Entity, "field_70134_J", "Z");
        if(isInWeb != nullptr){
            (*env).SetBooleanField(entity, isInWeb, true);
        }
        jfieldID fire = (*env).GetFieldID(Entity, "field_190534_ay", "I");
        if(fire != nullptr){
            (*env).SetIntField(entity,fire,2147483647);
        }
        jfieldID isAddedToWorld = (*env).GetFieldID(Entity, "isAddedToWorld", "Z");
        if(isAddedToWorld != nullptr){
            (*env).SetBooleanField(entity,isAddedToWorld, false);
        }
        jfieldID isDead = (*env).GetFieldID(Entity, "field_70128_L", "Z");
        if(isDead != nullptr){
            (*env).SetBooleanField(entity,isDead, true);
        }
        jfieldID dataManager = (*env).GetFieldID(Entity, "field_70180_af",
                                                 "Lnet/minecraft/network/datasync/DataParameter<Ljava/lang/Byte;>;");
        jfieldID velocityChanged = (*env).GetFieldID(Entity, "field_70133_I", "Z");
        if(velocityChanged != nullptr){
            (*env).SetBooleanField(entity,velocityChanged, true);
        }
        if ((*env).IsInstanceOf(entity, EntityLivingBase)) {
            jfieldID limbSwingAmount = (*env).GetFieldID(EntityLivingBase, "field_70721_aZ", "F");
            if(limbSwingAmount != nullptr){
                (*env).SetFloatField(entity,limbSwingAmount,1.5F);
            }
            jfieldID idleTime = (*env).GetFieldID(EntityLivingBase, "field_70708_bq", "I");
            if(idleTime != nullptr){
                (*env).SetIntField(entity,idleTime,0);
            }
            jfieldID lastDamage = (*env).GetFieldID(EntityLivingBase, "field_110153_bc", "I");
            if(lastDamage != nullptr){
                (*env).SetIntField(entity,lastDamage,2147483647);
            }
            jfieldID recentlyHit = (*env).GetFieldID(EntityLivingBase, "field_70718_bc", "I");
            if(recentlyHit != nullptr){
                (*env).SetIntField(entity,recentlyHit,60);
            }
            jfieldID revengeTarget = (*env).GetFieldID(EntityLivingBase, "field_70755_b",
                                                       "Lnet/minecraft/entity/EntityLivingBase;");
            if(revengeTarget != nullptr){
                (*env).SetObjectField(entity,revengeTarget, nullptr);
            }
            jfieldID revengeTimer = (*env).GetFieldID(EntityLivingBase, "field_70756_c", "I");
            if(revengeTimer != nullptr){
                (*env).SetIntField(entity,revengeTimer,0);
            }
            jfieldID activePotionsMap = (*env).GetFieldID(EntityLivingBase, "field_70713_bf",
                                                          "Ljava/util/Map;");
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
                    jfieldID HEALTH_ID = (*env).GetStaticFieldID(EntityLivingBase, "field_184632_c",
                                                                 "Lnet/minecraft/network/datasync/DataParameter;");
                    if(HEALTH_ID != nullptr){
                        jobject HEALTH = (*env).GetStaticObjectField(EntityLivingBase, HEALTH_ID);
                        if (HEALTH != nullptr) {
                            if(EntityDataManager != nullptr){
                                jmethodID set = (*env).GetMethodID(EntityDataManager, "func_187227_b",
                                                                   "(Lnet/minecraft/network/datasync/DataParameter;Ljava/lang/Object;)V");
                                if(set != nullptr){
                                    (*env).CallVoidMethod(manager,set,HEALTH,0.0f);
                                }
                            }
                        }
                    }
                }
            }
            jfieldID attributeMap_ID = (*env).GetFieldID(EntityLivingBase, "field_110155_d",
                                                         "Lnet/minecraft/entity/ai/attributes/AbstractAttributeMap;");
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
            jfieldID dead = (*env).GetFieldID(EntityLivingBase, "field_70729_aU", "Z");
            if (dead != nullptr) {
                (*env).SetBooleanField(entity, dead, true);
            }
            jfieldID deathTime = (*env).GetFieldID(EntityLivingBase, "field_70725_aQ", "I");
            if (deathTime != nullptr) {
                (*env).SetIntField(entity, deathTime, 2147483647);
            }
            jfieldID attackingPlayer = (*env).GetFieldID(EntityLivingBase, "field_70717_bb",
                                                         "Lnet/minecraft/entity/player/EntityPlayer;");
            if (attackingPlayer != nullptr) {
                (*env).SetObjectField(entity, attackingPlayer, nullptr);
            }
            jfieldID lastAttackedEntity = (*env).GetFieldID(EntityLivingBase, "field_110150_bn",
                                                            "Lnet/minecraft/entity/EntityLivingBase;");
            if (lastAttackedEntity != nullptr) {
                (*env).SetObjectField(entity, lastAttackedEntity, nullptr);
            }
            jfieldID lastAttackedEntityTime = (*env).GetFieldID(EntityLivingBase, "field_142016_bo", "I");
            if (lastAttackedEntityTime != nullptr) {
                (*env).SetIntField(entity, lastAttackedEntityTime, 0);
            }
            jfieldID absorptionAmount = (*env).GetFieldID(EntityLivingBase, "field_110151_bq", "I");
            if (absorptionAmount != nullptr) {
                (*env).SetIntField(entity, absorptionAmount, 0);
            }
            jfieldID combatTracker = (*env).GetFieldID(EntityLivingBase, "field_94063_bt",
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
            if ((*env).IsInstanceOf(entity, EntityLiving)) {
                if (dataManager != nullptr) {
                    jobject manager = (*env).GetObjectField(entity, dataManager);
                    if (manager != nullptr) {
                        jfieldID AI_FLAGS_ID = (*env).GetStaticFieldID(EntityLivingBase, "field_184654_a",
                                                                       "Lnet/minecraft/network/datasync/DataParameter;");
                        if (AI_FLAGS_ID != nullptr) {
                            jobject AI_FLAGS = (*env).GetStaticObjectField(EntityLivingBase, AI_FLAGS_ID);
                            if (AI_FLAGS != nullptr) {
                                if (EntityDataManager != nullptr) {
                                    jmethodID set = (*env).GetMethodID(EntityDataManager, "func_187227_b",
                                                                       "(Lnet/minecraft/network/datasync/DataParameter;Ljava/lang/Object;)V");
                                    if (set != nullptr) {
                                        (*env).CallVoidMethod(manager, set, AI_FLAGS, (jbyte) 1);
                                    }
                                }
                            }
                        }
                    }
                }
                if (NonNullList != nullptr) {
                    jmethodID constructor = (*env).GetMethodID(NonNullList, "withSize",
                                                               "(ILjava/lang/Object;)Lnet/minecraft/util/NonNullList;");
                    if (constructor != nullptr) {
                        if (EMPTY != nullptr) {
                            jfieldID inventoryHands = (*env).GetFieldID(EntityLiving, "field_184656_bv",
                                                                        "Lnet/minecraft/util/NonNullList;");
                            if (inventoryHands != nullptr) {
                                (*env).SetObjectField(entity, inventoryHands,
                                                      (*env).NewObject(NonNullList, constructor, 2, EMPTY));
                            }

                            jfieldID inventoryArmor = (*env).GetFieldID(EntityLiving, "field_184657_bw",
                                                                        "Lnet/minecraft/util/NonNullList;");
                            if (inventoryArmor != nullptr) {
                                (*env).SetObjectField(entity, inventoryArmor,
                                                      (*env).NewObject(NonNullList, constructor, 4, EMPTY));
                            }
                        }
                    }
                }
                if ((*env).IsInstanceOf(entity, EntityPlayer)) {
                    if (InventoryBasic != nullptr) {
                        jfieldID inventoryContents = (*env).GetFieldID(InventoryBasic, "field_70482_c",
                                                                       "Lnet/minecraft/util/NonNullList;");
                        if (inventoryContents != nullptr) {
                            if (NonNullList != nullptr) {
                                jmethodID constructor = (*env).GetMethodID(NonNullList, "withSize",
                                                                           "(ILjava/lang/Object;)Lnet/minecraft/util/NonNullList;");
                                if (constructor != nullptr) {
                                    jfieldID enderChest = (*env).GetFieldID(EntityPlayer, "field_71078_a",
                                                                            "Lnet/minecraft/inventory_id/InventoryEnderChest;");
                                    if (enderChest != nullptr) {
                                        (*env).SetObjectField(entity, enderChest,
                                                              (*env).NewObject(NonNullList, constructor, 27, EMPTY));
                                    }

                                    jfieldID inventory_id = (*env).GetFieldID(EntityPlayer, "field_71071_by",
                                                                              "Lnet/minecraft/entity/player/InventoryPlayer;");
                                    if (inventory_id != nullptr) {
                                        jobject inventory = (*env).GetObjectField(entity, inventory_id);
                                        if (InventoryPlayer != nullptr) {
                                            jfieldID mainInventory = (*env).GetFieldID(InventoryPlayer, "field_70462_a",
                                                                                       "Lnet/minecraft/util/NonNullList;");
                                            if (mainInventory != nullptr) {
                                                (*env).SetObjectField(inventory, mainInventory,
                                                                      (*env).NewObject(NonNullList, constructor, 36,
                                                                                       EMPTY));
                                            }
                                            jfieldID armorInventory = (*env).GetFieldID(InventoryPlayer,
                                                                                        "field_70460_b",
                                                                                        "Lnet/minecraft/util/NonNullList;");
                                            if (armorInventory != nullptr) {
                                                (*env).SetObjectField(inventory, armorInventory,
                                                                      (*env).NewObject(NonNullList, constructor, 4,
                                                                                       EMPTY));
                                            }
                                            jfieldID offHandInventory = (*env).GetFieldID(InventoryPlayer,
                                                                                          "field_184439_c",
                                                                                          "Lnet/minecraft/util/NonNullList;");
                                            if (offHandInventory != nullptr) {
                                                (*env).SetObjectField(inventory, offHandInventory,
                                                                      (*env).NewObject(NonNullList, constructor, 1,
                                                                                       EMPTY));
                                            }
                                            jfieldID itemStack = (*env).GetFieldID(InventoryPlayer, "field_70457_g",
                                                                                   "Lnet/minecraft/item/ItemStack;");
                                            if (itemStack != nullptr) {
                                                (*env).SetObjectField(inventory, itemStack, EMPTY);
                                            }
                                            if (ArrayList != nullptr) {
                                                jmethodID Constructor = (*env).GetMethodID(ArrayList, "<init>", "(I)V");
                                                if (Constructor != nullptr) {
                                                    jfieldID allInventories = (*env).GetFieldID(InventoryPlayer,
                                                                                                "field_184440_g",
                                                                                                "Ljava/util/List;");
                                                    (*env).SetObjectField(inventory, allInventories,
                                                                          (*env).NewObject(ArrayList, Constructor));
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
        }
        if (World != nullptr) {
            jfieldID world_id = (*env).GetFieldID(Entity, "field_70170_p", "Lnet/minecraft/world/World;");
            if (world_id != nullptr) {
                jobject world = (*env).GetObjectField(entity, world_id);
                if (world != nullptr) {
                    if (ArrayList != nullptr) {
                        jmethodID remove = (*env).GetMethodID(ArrayList, "remove", "(Ljava/lang/Object;)Z");
                        if (remove != nullptr) {
                            jfieldID playerEntities_id = (*env).GetFieldID(World, "field_73010_i",
                                                                           "Ljava/util/List;");
                            if (playerEntities_id != nullptr) {
                                jobject playerEntities = (*env).GetObjectField(world, playerEntities_id);
                                (*env).CallBooleanMethod(playerEntities, remove, entity);
                            }

                            jfieldID weatherEffects_id = (*env).GetFieldID(World, "field_73007_j",
                                                                           "Ljava/util/List;");
                            if (weatherEffects_id != nullptr) {
                                jobject weatherEffects = (*env).GetObjectField(world, weatherEffects_id);
                                (*env).CallBooleanMethod(weatherEffects, remove, entity);
                            }
                        }

                        jmethodID list_size = (*env).GetMethodID(ArrayList, "size", "()I");
                        jmethodID list_get = (*env).GetMethodID(ArrayList, "get", "(I)Ljava/lang/Object;");;
                        if (list_size != nullptr && list_get != nullptr) {
                            if (IWorldEventListener != nullptr) {
                                jfieldID eventListeners_id = (*env).GetFieldID(World, "field_73021_x",
                                                                               "Ljava/util/List;");
                                if (eventListeners_id != nullptr) {
                                    jobject eventListeners = (*env).GetObjectField(world, eventListeners_id);
                                    if (eventListeners != nullptr) {
                                        int size = (*env).CallIntMethod(eventListeners, list_size);
                                        for (int i = 0; i < size; i++) {
                                            jobject listener = (*env).CallObjectMethod(eventListeners, list_get, i);
                                            if (listener != nullptr) {
                                                jmethodID onEntityRemoved = (*env).GetMethodID(IWorldEventListener,
                                                                                               "func_72709_b",
                                                                                               "(Lnet/minecraft/entity/Entity;)V");
                                                if (onEntityRemoved != nullptr) {
                                                    (*env).CallVoidMethod(listener, onEntityRemoved, entity);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (Chunk != nullptr) {
                        jmethodID getChunk = (*env).GetMethodID(World, "func_72964_e",
                                                                "(II)Lnet/minecraft/world/chunk/Chunk;");
                        if (getChunk != nullptr) {
                            jfieldID chunkCoordX = (*env).GetFieldID(Entity, "field_70176_ah", "I");
                            jfieldID chunkCoordZ = (*env).GetFieldID(Entity, "field_70164_aj", "I");
                            if (chunkCoordX != nullptr && chunkCoordZ != nullptr) {
                                jint x = (*env).GetIntField(entity, chunkCoordX), z = (*env).GetIntField(entity,
                                                                                                         chunkCoordZ);
                                jobject chunk = (*env).CallObjectMethod(world, getChunk, x, z);
                                if (chunk != nullptr) {
                                    jfieldID entityLists_id = (*env).GetFieldID(Chunk, "field_76645_j",
                                                                                "[Lnet/minecraft/util/ClassInheritanceMultiMap;");
                                    if (entityLists_id != nullptr) {
                                        auto entityLists = static_cast<jobjectArray>((*env).GetObjectField(chunk,
                                                                                                           entityLists_id));
                                        if (entityLists != nullptr) {
                                            jfieldID chunkCoordY = (*env).GetFieldID(Entity, "field_70162_ai", "I");
                                            if (chunkCoordY != nullptr) {
                                                int y = (*env).GetIntField(entity, chunkCoordY);
                                                if (y < 0)(*env).SetIntField(entity, chunkCoordY, 0);
                                                if (y > (*env).GetArrayLength(entityLists))
                                                    (*env).SetIntField(entity, chunkCoordY, (*env).GetArrayLength(
                                                            entityLists) - 1);
                                                if (ClassInheritanceMultiMap != nullptr) {
                                                    jmethodID remove = (*env).GetMethodID(ClassInheritanceMultiMap,
                                                                                          "remove",
                                                                                          "(Ljava/lang/Object;)Z");
                                                    if (remove != nullptr) {
                                                        jobject classInheritanceMultiMap = (*env).GetObjectArrayElement(
                                                                entityLists, (*env).GetIntField(entity, chunkCoordY));
                                                        if (classInheritanceMultiMap != nullptr) {
                                                            (*env).CallBooleanMethod(classInheritanceMultiMap, remove,
                                                                                     entity);
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                    }
                                    jfieldID dirty = (*env).GetFieldID(Chunk, "field_76643_l", "Z");
                                    if (dirty != nullptr) {
                                        (*env).SetBooleanField(chunk, dirty, true);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (Minecraft != nullptr) {
            if (WorldClient != nullptr) {
                jfieldID minecraft_id = (*env).GetStaticFieldID(Minecraft, "field_71432_P",
                                                                "Lnet/minecraft/client/Minecraft;");
                if (minecraft_id != nullptr) {
                    jobject minecraft = (*env).GetStaticObjectField(Minecraft, minecraft_id);
                    if (minecraft != nullptr) {
                        jfieldID world_id = (*env).GetFieldID(Minecraft, "field_71441_e",
                                                              "Lnet/minecraft/client/multiplayer/WorldClient;");
                        if (world_id != nullptr) {
                            jobject world = (*env).GetObjectField(minecraft, world_id);
                            if (world != nullptr) {
                                if (HashSet != nullptr) {
                                    jmethodID remove = (*env).GetMethodID(HashSet, "remove", "(Ljava/lang/Object;)Z");
                                    if (remove != nullptr) {
                                        jfieldID entityList_id = (*env).GetFieldID(WorldClient, "field_73032_d",
                                                                                   "Ljava/util/Set;");
                                        if (entityList_id != nullptr) {
                                            jobject entityList = (*env).GetObjectField(world, entityList_id);
                                            if (entityList != nullptr) {
                                                (*env).CallBooleanMethod(entityList, remove, entity);
                                            }
                                        }
                                        jfieldID entitySpawnQueue_id = (*env).GetFieldID(WorldClient, "field_73036_L",
                                                                                         "Ljava/util/Set;");
                                        if (entitySpawnQueue_id != nullptr) {
                                            jobject entitySpawnQueue = (*env).GetObjectField(world,
                                                                                             entitySpawnQueue_id);
                                            if (entitySpawnQueue != nullptr) {
                                                (*env).CallBooleanMethod(entitySpawnQueue, remove, entity);
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
    }
}

JNIEXPORT jint JNICALL Java_miku_lib_common_Native_NativeUtil_TEST
        (JNIEnv *env, jclass cls){
    std::cout << "Hello world!\n";
    printf("Hello World!\n");
    return 39;
}