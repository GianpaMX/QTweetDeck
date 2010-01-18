#ifndef QTWEETSTATUSLISTMODEL_H
#define QTWEETSTATUSLISTMODEL_H

#define QTWEETSTATUSLISTMODEL_COLUMNS   1

#include <QAbstractTableModel>
#include <QStringList>

#include "qtweetstatuslist.h"

#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweetStatusListModel : public QAbstractTableModel {
    Q_OBJECT
    public:
        explicit QTweetStatusListModel(QObject *parent = 0);
        explicit QTweetStatusListModel(const QTweetStatusList &statuslist, QObject *parent = 0);

        void setStatusList(const QTweetStatusList &statuslist);
        QTweetStatusList StatusList() const;


        virtual QVariant data(const QModelIndex & index, int role) const;
        virtual int rowCount (const QModelIndex & parent = QModelIndex()) const;
        virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    signals:

    public slots:

    private:
        static QStringList headerText;
        QTweetStatusList statusList;
};

#endif // QTWEETSTATUSLISTMODEL_H
