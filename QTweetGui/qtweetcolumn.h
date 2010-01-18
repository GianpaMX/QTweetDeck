#ifndef QTWEETCOLUMN_H
#define QTWEETCOLUMN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>

#include "qtweetcolumntitle.h"
#include "qtweetcolumnbuttons.h"
#include "qtweetstatuslist.h"
#include "qtweetstatuslistmodel.h"

#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweetColumn : public QWidget {
    Q_OBJECT
    public:
    explicit QTweetColumn(const QString &title = "", QWidget * parent = 0);
    explicit QTweetColumn(const QTweetStatusList& list, const QString &title = "", QWidget * parent = 0);
        ~QTweetColumn();
    private:
        QVBoxLayout* layout;
        QTweetColumnTitle* columnTitle;
        QTweetColumnButtons* columnButtons;
        QTableView* time_line;
        QTweetStatusListModel* time_line_model;
};

#endif // QTWEETCOLUMN_H
