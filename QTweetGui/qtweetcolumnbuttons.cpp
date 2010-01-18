#include "qtweetcolumnbuttons.h"

QTweetColumnButtons::QTweetColumnButtons(QWidget *parent) : QWidget(parent) {
    layout = new QHBoxLayout;

    QPushButton* button;

    button = new QPushButton("Cloud");
    buttons.append(button);
    button = new QPushButton("Filter");
    buttons.append(button);
    button = new QPushButton("Mark");
    buttons.append(button);
    button = new QPushButton("Clear");
    buttons.append(button);
    button = new QPushButton("Clear All");
    buttons.append(button);
    button = new QPushButton("Move Right");
    buttons.append(button);

    foreach(QPushButton *button, buttons) {
        layout->addWidget(button);
    }

    setLayout(layout);
}

QTweetColumnButtons::~QTweetColumnButtons() {
    foreach(QPushButton *button, buttons) {
        if(button) delete button;
    }
    if(layout) delete layout;
}
