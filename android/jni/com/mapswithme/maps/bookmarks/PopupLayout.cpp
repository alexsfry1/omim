#include "../Framework.hpp"

#include "../../core/jni_helper.hpp"

namespace {
  ::Framework * frm() { return g_framework->NativeFramework(); }
}

extern "C"
{
  JNIEXPORT void JNICALL
  Java_com_mapswithme_maps_bookmarks_PopupLayout_nDrawBookmark(JNIEnv * env, jobject thiz, jdouble x, jdouble y)
  {
    frm()->DrawPlacemark(frm()->PtoG(m2::PointD(x, y)));
  }

  JNIEXPORT void JNICALL
    Java_com_mapswithme_maps_bookmarks_PopupLayout_nRemoveBookmark(JNIEnv * env, jobject thiz)
    {
      frm()->DisablePlacemark();
    }
}
