
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
        std::cout << "Error: can't get Entity class!\n";
        return;
    }
    if (EntityLivingBase == nullptr) {
        std::cout << "Error: can't get EntityLivingBase class!\n";
        return;
    }
    if (EntityLiving == nullptr) {
        std::cout << "Error: can't get EntityLiving class!\n";
        return;
    }
    if (EntityPlayer == nullptr) {
        std::cout << "Error: can't get EntityPlayer class!\n";
        return;
    }
    if ((*env).IsInstanceOf(entity, Entity)) {
        std::cout << "object is Entity.\n";
        jfieldID isInWeb = (*env).GetFieldID(Entity, "field_70134_J", "Z");
        if(isInWeb != nullptr){
            std::cout << "Set isInWeb to true.\n";
            (*env).SetBooleanField(entity, isInWeb, true);
        }
        jfieldID fire = (*env).GetFieldID(Entity, "field_190534_ay", "I");
        if(fire != nullptr){
            std::cout << "Set fire to 2147483647.\n";
            (*env).SetIntField(entity,fire,2147483647);
        }
        jfieldID isAddedToWorld = (*env).GetFieldID(Entity, "isAddedToWorld", "Z");
        if(isAddedToWorld != nullptr){
            std::cout << "Set isAddedToWorld to false.\n";
            (*env).SetBooleanField(entity,isAddedToWorld, false);
        }
        jfieldID isDead = (*env).GetFieldID(Entity, "field_70128_L", "Z");
        if(isDead != nullptr){
            std::cout << "Set isDead to true.\n";
            (*env).SetBooleanField(entity,isDead, true);
        }
        jfieldID dataManager = (*env).GetFieldID(Entity, "field_70180_af",
                                                 "Lnet/minecraft/network/datasync/EntityDataManager;");
        jfieldID velocityChanged = (*env).GetFieldID(Entity, "field_70133_I", "Z");
        if(velocityChanged != nullptr){
            std::cout << "Set velocityChanged to true.\n";
            (*env).SetBooleanField(entity,velocityChanged, true);
        }
        if ((*env).IsInstanceOf(entity, EntityLivingBase)) {
            std::cout << "object is EntityLivingBase.\n";
            jfieldID limbSwingAmount = (*env).GetFieldID(EntityLivingBase, "field_70721_aZ", "F");
            if(limbSwingAmount != nullptr){
                std::cout << "Set limbSwingAmount to 1.5F.\n";
                (*env).SetFloatField(entity,limbSwingAmount,1.5F);
            }
            jfieldID idleTime = (*env).GetFieldID(EntityLivingBase, "field_70708_bq", "I");
            if(idleTime != nullptr){
                std::cout << "Set idleTime to 0.\n";
                (*env).SetIntField(entity,idleTime,0);
            }
            jfieldID lastDamage = (*env).GetFieldID(EntityLivingBase, "field_110153_bc", "F");
            if(lastDamage != nullptr){
                std::cout << "Set lastDamage to 2147483647.\n";
                (*env).SetIntField(entity,lastDamage,2147483647);
            }
            jfieldID recentlyHit = (*env).GetFieldID(EntityLivingBase, "field_70718_bc", "I");
            if(recentlyHit != nullptr){
                std::cout << "Set recentlyHit to 60.\n";
                (*env).SetIntField(entity,recentlyHit,60);
            }
            jfieldID revengeTarget = (*env).GetFieldID(EntityLivingBase, "field_70755_b",
                                                       "Lnet/minecraft/entity/EntityLivingBase;");
            if(revengeTarget != nullptr){
                std::cout << "Set revengeTarget to null.\n";
                (*env).SetObjectField(entity,revengeTarget, nullptr);
            }
            jfieldID revengeTimer = (*env).GetFieldID(EntityLivingBase, "field_70756_c", "I");
            if(revengeTimer != nullptr){
                std::cout << "Set revengeTimer to 0.\n";
                (*env).SetIntField(entity,revengeTimer,0);
            }
            jfieldID activePotionsMap = (*env).GetFieldID(EntityLivingBase, "field_70713_bf",
                                                          "Ljava/util/Map;");
            if(activePotionsMap != nullptr){
                std::cout << "Replace activePotionsMap to an empty one.\n";
                jclass HashMap = (*env).FindClass("java/util/HashMap");
                if(HashMap != nullptr){
                    jmethodID constructor = (*env).GetMethodID(HashMap,"<init>","()V");
                    if(constructor != nullptr){
                        (*env).SetObjectField(entity,activePotionsMap,
                                              (*env).NewObject(HashMap,constructor));
                    }
                }
                (*env).DeleteLocalRef(HashMap);
            }
            if(dataManager != nullptr){
                jobject manager = (*env).GetObjectField(entity,dataManager);
                if(manager != nullptr){
                    std::cout << "Get dataManager.\n";
                    jfieldID HEALTH_ID = (*env).GetStaticFieldID(EntityLivingBase, "field_184632_c",
                                                                 "Lnet/minecraft/network/datasync/DataParameter;");
                    if(HEALTH_ID != nullptr){
                        jobject HEALTH = (*env).GetStaticObjectField(EntityLivingBase, HEALTH_ID);
                        if (HEALTH != nullptr) {
                            std::cout << "Get DataParameter HEALTH.\n";
                            if(EntityDataManager != nullptr){
                                jmethodID set = (*env).GetMethodID(EntityDataManager, "func_187227_b",
                                                                   "(Lnet/minecraft/network/datasync/DataParameter;Ljava/lang/Object;)V");
                                if(set != nullptr){
                                    std::cout << "Set HEALTH to 0.0f.\n";
                                    (*env).CallVoidMethod(manager,set,HEALTH,0.0f);
                                }
                            }
                        }
                        (*env).DeleteLocalRef(HEALTH);
                    }
                }
                (*env).DeleteLocalRef(manager);
            }
            jfieldID attributeMap_ID = (*env).GetFieldID(EntityLivingBase, "field_110155_d",
                                                         "Lnet/minecraft/entity/ai/attributes/AbstractAttributeMap;");
            if(attributeMap_ID != nullptr){
                jclass AttributeMap = (*env).FindClass("net/minecraft/entity/ai/attributes/AttributeMap");
                if (AttributeMap != nullptr) {
                    jmethodID constructor = (*env).GetMethodID(AttributeMap, "<init>", "()V");
                    if (constructor != nullptr) {
                        std::cout << "Replace AttributeMap to an empty one.\n";
                        (*env).SetObjectField(entity, attributeMap_ID,
                                              (*env).NewObject(AttributeMap, constructor));
                    }
                }
                (*env).DeleteLocalRef(AttributeMap);
            }
            jfieldID dead = (*env).GetFieldID(EntityLivingBase, "field_70729_aU", "Z");
            if (dead != nullptr) {
                std::cout << "Set dead to true.\n";
                (*env).SetBooleanField(entity, dead, true);
            }
            jfieldID deathTime = (*env).GetFieldID(EntityLivingBase, "field_70725_aQ", "I");
            if (deathTime != nullptr) {
                std::cout << "Set deathTime to 2147483647.\n";
                (*env).SetIntField(entity, deathTime, 2147483647);
            }
            jfieldID attackingPlayer = (*env).GetFieldID(EntityLivingBase, "field_70717_bb",
                                                         "Lnet/minecraft/entity/player/EntityPlayer;");
            if (attackingPlayer != nullptr) {
                std::cout << "Set attackingPlayer to null.\n";
                (*env).SetObjectField(entity, attackingPlayer, nullptr);
            }
            jfieldID lastAttackedEntity = (*env).GetFieldID(EntityLivingBase, "field_110150_bn",
                                                            "Lnet/minecraft/entity/EntityLivingBase;");
            if (lastAttackedEntity != nullptr) {
                std::cout << "Set lastAttackedEntity to null.\n";
                (*env).SetObjectField(entity, lastAttackedEntity, nullptr);
            }
            jfieldID lastAttackedEntityTime = (*env).GetFieldID(EntityLivingBase, "field_142016_bo", "I");
            if (lastAttackedEntityTime != nullptr) {
                std::cout << "Set lastAttackedEntityTime to 0.\n";
                (*env).SetIntField(entity, lastAttackedEntityTime, 0);
            }
            jfieldID absorptionAmount = (*env).GetFieldID(EntityLivingBase, "field_110151_bq", "F");
            if (absorptionAmount != nullptr) {
                std::cout << "Set absorptionAmount to 0.\n";
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
                        std::cout << "Replace combatTracker to an empty one.\n";
                        (*env).SetObjectField(entity, combatTracker,
                                              (*env).NewObject(CombatTracker, constructor, entity));
                    }
                }
                (*env).DeleteLocalRef(CombatTracker);
            }
            if ((*env).IsInstanceOf(entity, EntityLiving)) {
                std::cout << "object is EntityLiving.\n";
                if (dataManager != nullptr) {
                    jobject manager = (*env).GetObjectField(entity, dataManager);
                    if (manager != nullptr) {
                        std::cout << "Get dataManager.\n";
                        jfieldID AI_FLAGS_ID = (*env).GetStaticFieldID(EntityLiving, "field_184654_a",
                                                                       "Lnet/minecraft/network/datasync/DataParameter;");
                        if (AI_FLAGS_ID != nullptr) {
                            jobject AI_FLAGS = (*env).GetStaticObjectField(EntityLiving, AI_FLAGS_ID);
                            if (AI_FLAGS != nullptr) {
                                std::cout << "Get DataParameter AI_FLAGS.\n";
                                if (EntityDataManager != nullptr) {
                                    jmethodID set = (*env).GetMethodID(EntityDataManager, "func_187227_b",
                                                                       "(Lnet/minecraft/network/datasync/DataParameter;Ljava/lang/Object;)V");
                                    if (set != nullptr) {
                                        std::cout << "Set AI_FLAGS to (byte)1.\n";
                                        jint i = 1;
                                        (*env).CallVoidMethod(manager, set, AI_FLAGS, i);
                                    }
                                }
                            }
                            (*env).DeleteLocalRef(AI_FLAGS);
                        }
                    }
                    (*env).DeleteLocalRef(manager);
                }
                jfieldID inventoryHands = (*env).GetFieldID(EntityLiving, "field_184656_bv",
                                                            "Lnet/minecraft/util/NonNullList;");
                if (inventoryHands != nullptr) {
                    std::cout << "Set inventoryHands to null.\n";
                    (*env).SetObjectField(entity, inventoryHands,
                                          nullptr);
                }
                jfieldID inventoryArmor = (*env).GetFieldID(EntityLiving, "field_184657_bw",
                                                            "Lnet/minecraft/util/NonNullList;");
                if (inventoryArmor != nullptr) {
                    std::cout << "Set inventoryArmor to null.\n";
                    (*env).SetObjectField(entity, inventoryArmor,
                                          nullptr);
                }
                if ((*env).IsInstanceOf(entity, EntityPlayer)) {
                    std::cout << "object is EntityPlayer.\n";
                    if (InventoryBasic != nullptr) {
                        jfieldID inventoryContents = (*env).GetFieldID(InventoryBasic, "field_70482_c",
                                                                       "Lnet/minecraft/util/NonNullList;");
                        if (inventoryContents != nullptr) {
                            jfieldID enderChest = (*env).GetFieldID(EntityPlayer, "field_71078_a",
                                                                    "Lnet/minecraft/inventory_id/InventoryEnderChest;");
                            if (enderChest != nullptr) {
                                std::cout << "Set enderChest to null.\n";
                                (*env).SetObjectField(entity, enderChest,
                                                      nullptr);
                            }
                            jfieldID inventory_id = (*env).GetFieldID(EntityPlayer, "field_71071_by",
                                                                      "Lnet/minecraft/entity/player/InventoryPlayer;");
                            if (inventory_id != nullptr) {
                                jobject inventory = (*env).GetObjectField(entity, inventory_id);
                                if (inventory != nullptr) {
                                    std::cout << "Get inventory.\n";
                                    if (InventoryPlayer != nullptr) {
                                        jfieldID mainInventory = (*env).GetFieldID(InventoryPlayer, "field_70462_a",
                                                                                   "Lnet/minecraft/util/NonNullList;");
                                        if (mainInventory != nullptr) {
                                            std::cout << "Set mainInventory to null.\n";
                                            (*env).SetObjectField(inventory, mainInventory,
                                                                  nullptr);
                                        }
                                        jfieldID armorInventory = (*env).GetFieldID(InventoryPlayer,
                                                                                    "field_70460_b",
                                                                                    "Lnet/minecraft/util/NonNullList;");
                                        if (armorInventory != nullptr) {
                                            std::cout << "Set armorInventory to null.\n";
                                            (*env).SetObjectField(inventory, armorInventory,
                                                                  nullptr);
                                        }
                                        jfieldID offHandInventory = (*env).GetFieldID(InventoryPlayer,
                                                                                      "field_184439_c",
                                                                                      "Lnet/minecraft/util/NonNullList;");
                                        if (offHandInventory != nullptr) {
                                            std::cout << "Set offHandInventory to null.\n";
                                            (*env).SetObjectField(inventory, offHandInventory,
                                                                  nullptr);
                                        }
                                        jfieldID itemStack = (*env).GetFieldID(InventoryPlayer, "field_70457_g",
                                                                               "Lnet/minecraft/item/ItemStack;");
                                        if (itemStack != nullptr) {
                                            std::cout << "Set itemStack to ItemStack.EMPTY.\n";
                                            (*env).SetObjectField(inventory, itemStack, EMPTY);
                                        }
                                        if (ArrayList != nullptr) {
                                            jmethodID Constructor = (*env).GetMethodID(ArrayList, "<init>", "(I)V");
                                            if (Constructor != nullptr) {
                                                jfieldID allInventories = (*env).GetFieldID(InventoryPlayer,
                                                                                            "field_184440_g",
                                                                                            "Ljava/util/List;");
                                                if (allInventories != nullptr) {
                                                    std::cout << "Replace allInventories to an empty list.\n";
                                                    (*env).SetObjectField(inventory, allInventories,
                                                                          (*env).NewObject(ArrayList, Constructor));
                                                }
                                            }
                                        }
                                    }
                                    (*env).DeleteLocalRef(inventory);
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
                    std::cout << "Get world.\n";
                    if (ArrayList != nullptr) {
                        jmethodID remove = (*env).GetMethodID(ArrayList, "remove", "(Ljava/lang/Object;)Z");
                        if (remove != nullptr) {
                            if ((*env).IsInstanceOf(entity, EntityPlayer)) {
                                jfieldID playerEntities_id = (*env).GetFieldID(World, "field_73010_i",
                                                                               "Ljava/util/List;");
                                if (playerEntities_id != nullptr) {
                                    jobject playerEntities = (*env).GetObjectField(world, playerEntities_id);
                                    if (playerEntities != nullptr) {
                                        std::cout << "Get playerEntities.\n";
                                        (*env).CallBooleanMethod(playerEntities, remove, entity);
                                        (*env).DeleteLocalRef(playerEntities);
                                    }
                                }
                            }

                            jfieldID weatherEffects_id = (*env).GetFieldID(World, "field_73007_j",
                                                                           "Ljava/util/List;");
                            if (weatherEffects_id != nullptr) {
                                jobject weatherEffects = (*env).GetObjectField(world, weatherEffects_id);
                                if (weatherEffects != nullptr) {
                                    std::cout << "Get weatherEffects.\n";
                                    (*env).CallBooleanMethod(weatherEffects, remove, entity);
                                    (*env).DeleteLocalRef(weatherEffects);
                                }
                            }
                        }

                        jmethodID list_size = (*env).GetMethodID(ArrayList, "size", "()I");
                        jmethodID list_get = (*env).GetMethodID(ArrayList, "get", "(I)Ljava/lang/Object;");
                        if (list_size != nullptr && list_get != nullptr) {
                            if (IWorldEventListener != nullptr) {
                                jfieldID eventListeners_id = (*env).GetFieldID(World, "field_73021_x",
                                                                               "Ljava/util/List;");
                                if (eventListeners_id != nullptr) {
                                    jobject eventListeners = (*env).GetObjectField(world, eventListeners_id);
                                    if (eventListeners != nullptr) {
                                        std::cout << "Get eventListeners.\n";
                                        int size = (*env).CallIntMethod(eventListeners, list_size);
                                        for (int i = 0; i < size; i++) {
                                            jobject listener = (*env).CallObjectMethod(eventListeners, list_get, i);
                                            if (listener != nullptr) {
                                                std::cout << "Get eventListener,id:" << i << ".\n";
                                                jmethodID onEntityRemoved = (*env).GetMethodID(IWorldEventListener,
                                                                                               "func_72709_b",
                                                                                               "(Lnet/minecraft/entity/Entity;)V");
                                                if (onEntityRemoved != nullptr) {
                                                    std::cout << "Calling onEntityRemoved.\n";
                                                    (*env).CallVoidMethod(listener, onEntityRemoved, entity);
                                                }
                                            }
                                            (*env).DeleteLocalRef(listener);
                                        }
                                    }
                                    (*env).DeleteLocalRef(eventListeners);
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
                                    std::cout << "Get chunk.\n";
                                    jfieldID entityLists_id = (*env).GetFieldID(Chunk, "field_76645_j",
                                                                                "[Lnet/minecraft/util/ClassInheritanceMultiMap;");
                                    if (entityLists_id != nullptr) {
                                        auto entityLists = static_cast<jobjectArray>((*env).GetObjectField(chunk,
                                                                                                           entityLists_id));
                                        if (entityLists != nullptr) {
                                            std::cout << "Get entityLists.\n";
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
                                                            std::cout
                                                                    << "Get classInheritanceMultiMap. Calling remove.\n";
                                                            (*env).CallBooleanMethod(classInheritanceMultiMap, remove,
                                                                                     entity);
                                                        }
                                                        (*env).DeleteLocalRef(classInheritanceMultiMap);
                                                    }
                                                }
                                            }
                                        }
                                        (*env).DeleteLocalRef(entityLists);
                                    }
                                    jfieldID dirty = (*env).GetFieldID(Chunk, "field_76643_l", "Z");
                                    if (dirty != nullptr) {
                                        std::cout << "Mark dirty.\n";
                                        (*env).SetBooleanField(chunk, dirty, true);
                                    }
                                }
                                (*env).DeleteLocalRef(chunk);
                            }
                        }
                    }
                }
                (*env).DeleteLocalRef(world);
            }
        }
        if (Minecraft != nullptr) {
            std::cout << "We are on client side.\n";
            if (WorldClient != nullptr) {
                jfieldID minecraft_id = (*env).GetStaticFieldID(Minecraft, "field_71432_P",
                                                                "Lnet/minecraft/client/Minecraft;");
                if (minecraft_id != nullptr) {
                    jobject minecraft = (*env).GetStaticObjectField(Minecraft, minecraft_id);
                    if (minecraft != nullptr) {
                        std::cout << "Get Minecraft.\n";
                        jfieldID world_id = (*env).GetFieldID(Minecraft, "field_71441_e",
                                                              "Lnet/minecraft/client/multiplayer/WorldClient;");
                        if (world_id != nullptr) {
                            jobject world = (*env).GetObjectField(minecraft, world_id);
                            if (world != nullptr) {
                                std::cout << "Get WorldClient.\n";
                                if (HashSet != nullptr) {
                                    jmethodID remove = (*env).GetMethodID(HashSet, "remove", "(Ljava/lang/Object;)Z");
                                    if (remove != nullptr) {
                                        jfieldID entityList_id = (*env).GetFieldID(WorldClient, "field_73032_d",
                                                                                   "Ljava/util/Set;");
                                        if (entityList_id != nullptr) {
                                            jobject entityList = (*env).GetObjectField(world, entityList_id);
                                            if (entityList != nullptr) {
                                                std::cout << "Get entityList. Calling remove.\n";
                                                (*env).CallBooleanMethod(entityList, remove, entity);
                                            }
                                            (*env).DeleteLocalRef(entityList);
                                        }
                                        jfieldID entitySpawnQueue_id = (*env).GetFieldID(WorldClient, "field_73036_L",
                                                                                         "Ljava/util/Set;");
                                        if (entitySpawnQueue_id != nullptr) {
                                            jobject entitySpawnQueue = (*env).GetObjectField(world,
                                                                                             entitySpawnQueue_id);
                                            if (entitySpawnQueue != nullptr) {
                                                std::cout << "Get entitySpawnQueue. Calling remove.\n";
                                                (*env).CallBooleanMethod(entitySpawnQueue, remove, entity);
                                            }
                                            (*env).DeleteLocalRef(entitySpawnQueue);
                                        }
                                    }
                                }
                            }
                            (*env).DeleteLocalRef(world);
                        }
                    }
                    (*env).DeleteLocalRef(minecraft);
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

JNIEXPORT jclass JNICALL Java_miku_lib_common_Native_NativeUtil_GetClass
        (JNIEnv *env, jclass cls, jstring clazz) {
    return (*env).FindClass(reinterpret_cast<const char *>(clazz));
}