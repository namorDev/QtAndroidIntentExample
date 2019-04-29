#include "intent.h"
#include <QtAndroidExtras>
#include <QString>

Intent::Intent()
{

}

void Intent::send(const QString &extraMessage)
{
    QAndroidJniObject intent("android/content/Intent","()V");
    if (intent.isValid())
    {
        QAndroidJniObject param1 = QAndroidJniObject::fromString("org.qtproject.IntentReceiver");
        QAndroidJniObject param2 = QAndroidJniObject::fromString("org.qtproject.qt5.android.bindings.QtActivity");

        if ( param1.isValid() && param2.isValid())
        {
            intent.callObjectMethod("setClassName","(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;",param1.object<jobject>(),param2.object<jobject>());
            QAndroidJniObject subject = QAndroidJniObject::fromString("EXTRA_MESSAGE");
            QAndroidJniObject messageObject = QAndroidJniObject::fromString(extraMessage);
            intent.callObjectMethod("putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;", subject.object(), messageObject.object());
            QtAndroid::startActivity(intent,0);
        }
    }
}

