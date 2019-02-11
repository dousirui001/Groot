#ifndef SIDE_PANEL_EDITOR_H
#define SIDE_PANEL_EDITOR_H

#include <QFrame>
#include <QFile>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
#include "XML_utilities.hpp"

namespace Ui {
class SidepanelEditor;
}

class SidepanelEditor : public QFrame
{
    Q_OBJECT

public:
    explicit SidepanelEditor(QtNodes::DataModelRegistry* registry,
                             BT_NodeModels& tree_nodes_model,
                             QWidget *parent = nullptr);
    ~SidepanelEditor();

    void updateTreeView();

    void clear();

public slots:
    void onRemoveModel(QString selected_name, bool ask_confirmation);

    void onReplaceModel(const QString &old_name, const BT_NodeModel &new_model);


private slots:

    void on_paletteTreeWidget_itemSelectionChanged();

    void on_lineEditFilter_textChanged(const QString &arg1);

    void on_buttonAddNode_clicked();

    void onContextMenu(const QPoint &point);

    void on_buttonUpload_clicked();

    void on_buttonDownload_clicked();

    void on_buttonLock_toggled(bool checked);

signals:

    void addNewModel(const BT_NodeModel &new_model);

    void nodeModelEdited(QString prev_ID, QString new_ID);

    void destroySubtree(QString ID);

private:
    Ui::SidepanelEditor *ui;
    BT_NodeModels &_tree_nodes_model;
    QtNodes::DataModelRegistry* _model_registry;
    std::map<QString, QTreeWidgetItem*> _tree_view_category_items;

    BT_NodeModels importFromXML(QFile *file);

    BT_NodeModels importFromSkills(const QString& filename);

};

#endif // NODE_PALETTE_H
