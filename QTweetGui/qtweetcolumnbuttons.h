#ifndef QTWEETCOLUMNBUTTONS_H
#define QTWEETCOLUMNBUTTONS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>
#include <QPointer>

class QTweetColumnButtons : public QWidget {
    public:
        explicit QTweetColumnButtons(QWidget *parent = 0);
        ~QTweetColumnButtons();
    private:
        QPointer<QHBoxLayout> layout;
        QList< QPointer<QPushButton> > buttons;
};

#endif // QTWEETCOLUMNBUTTONS_H
