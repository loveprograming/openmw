#ifndef FILEDIALOG_HPP
#define FILEDIALOG_HPP

#include <QDialog>
#include <QModelIndex>

#include "components/contentselector/view/contentselector.hpp"
#include "ui_datafilespage.h"

class QDialogButtonBox;
class QSortFilterProxyModel;
class QAbstractItemModel;
class QPushButton;
class QStringList;
class QString;
class QMenu;
class QLabel;

class DataFilesModel;
class PluginsProxyModel;

namespace ContentSelectorView
{
    class LineEdit;
}

namespace CSVDoc
{
    class FileWidget;
    class AdjusterWidget;

    class FileDialog : public ContentSelectorView::ContentSelector
    {
        Q_OBJECT

        FileWidget *mFileWidget;
        AdjusterWidget *mAdjusterWidget;

        bool mEnable_1;
        bool mEnable_2;

    public:
        explicit FileDialog(QWidget *parent = 0);

        void openFile();
        void newFile();

        QString fileName();

    signals:
        void openFiles();
        void createNewFile();

        void signalUpdateCreateButton (bool, int);
        void signalUpdateCreateButtonFlags(int);

    public slots:

    private slots:
        //void updateViews();
        void updateOpenButton(const QStringList &items);
        void slotEnableCreateButton(bool enable, int widgetNumber);
        void slotAdjusterChanged(bool value);
        void slotGameFileSelected(int value);
    };
}
#endif // FILEDIALOG_HPP
