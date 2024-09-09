
#include <bits/stdc++.h>
#include <stdlib>
#include "org_neocities_a3441veryonline_obliteratingsword_UnsafeUtil.h"

JNIEXPORT jint JNICALL
Java_org_neocities_a3441veryonline_obliteratingsword_UnsafeUtil_sizeof (JNIEnv *env, jobject obj)
{
    return (jint) sizeof(obj);
}

JNIEXPORT jint JNICALL
Java_org_neocities_a3441veryonline_obliteratingsword_UnsafeUtil_malloc (JNIEnv *env, jint addr)
{
    return (jint)malloc((int)addr);
}

JNIEXPORT void JNICALL
Java_org_neocities_a3441veryonline_obliteratingsword_UnsafeUtil_free (JNIEnv *env, jint addr) {
    free((int)addr);
}

JNIEXPORT void JNICALL
Java_org_neocities_a3441veryonline_obliteratingsword_UnsafeUtil_destroy  (JNIEnv *env, jobject thingy)
{
    delete(thingy);
}
