#ifndef QTWEETCOLUMNBUTTONS_H
#define QTWEETCOLUMNBUTTONS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>

class QTweetColumnButtons : public QWidget {
    public:
        explicit QTweetColumnButtons(QWidget *parent = 0);
        ~QTweetColumnButtons();
    private:
        QHBoxLayout* layout;
        QList<QPushButton*> buttons;
};

#endif // QTWEETCOLUMNBUTTONS_H
