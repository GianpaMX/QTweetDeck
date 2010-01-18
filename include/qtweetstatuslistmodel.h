#ifndef QTWEETSTATUSLISTMODEL_H
#define QTWEETSTATUSLISTMODEL_H

#define QTWEETSTATUSLISTMODEL_COLUMNS   10

#include <QAbstractItemModel>
#include <QString>
#include <QStringList>

#include "qtweetstatuslist.h"

#include "QTweetGui_global.h"

class QTWEETGUISHARED_EXPORT QTweetStatusListModel : public QAbstractItemModel {
    Q_OBJECT
    public:
        explicit QTweetStatusListModel(QObject *parent = 0);
        explicit QTweetStatusListModel(const QTweetStatusList &statuslist, QObject *parent = 0);
        virtual ~QTweetStatusListModel();

        void setStatusList(const QTweetStatusList &statuslist);
        QTweetStatusList StatusList() const;

        virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
        virtual QModelIndex parent(const QModelIndex &index) const;

        virtual QVariant data(const QModelIndex & index, int role) const;
        virtual int rowCount (const QModelIndex & parent = QModelIndex()) const;
        virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    signals:
        void errorModeling(const QString& error);
    public slots:
        void addStatusList(const QTweetStatusList& statuslist, const QString& error);
    protected:
        static QStringList headerText;
        QTweetStatusList* statusList;
};

#endif // QTWEETSTATUSLISTMODEL_H
