#ifndef QTWEETCOLUMNTITLE_H
#define QTWEETCOLUMNTITLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>

#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweetColumnTitle : public QWidget {
    public:
        explicit QTweetColumnTitle(const QString &title = "", QWidget * parent = 0);
        ~QTweetColumnTitle();

        QString title() const;
        void setTitle(const QString &title);
    private:
        QPointer<QHBoxLayout> layout;
        QPointer<QLabel> columnTitle;
};

#endif // QTWEETCOLUMNTITLE_H
