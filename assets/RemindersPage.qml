import bb.cascades 1.0
import bb.system 1.0

//details page for the particular item in the list
Page {
    id: listPage
    property variant item
    property variant remindersModel
    property alias title: titleBar.title
    property variant control
    
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        title: listPage.item.index
    }
    Container {
        layout: DockLayout {
        }
        background: backgroundPaint.imagePaint 

        Container {
            leftPadding: 50
            rightPadding: leftPadding
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            
            Label {
                id: listText
                multiline: true
                text: listPage.item.text;
                textStyle.base: SystemDefaults.TextStyles.TitleText
                horizontalAlignment: HorizontalAlignment.Left
            }
        }
    }
    
     actions: [
            ActionItem {
                title: "Completed"
                imageSource: "asset:///images/completed.png"
                //ActionBar.placement: ActionBarPlacement.OnBar
                enabled: remindersModel.filter == "completed" ? false : true
                
                onTriggered: {
                    remindersModel.setICompletionStatus(listPage.item, "completed");
                    remindersModel.filter = "completed"
                    deletion.body = "Reminder completed! Victory at last!"
                    deletion.show();
                }
            },
            ActionItem {
                title: "Incomplete"
                imageSource: "asset:///images/incomplete.png"
                //ActionBar.placement: ActionBarPlacement.OnBar
                enabled: remindersModel.filter == "incomplete" ? false : true
                
                onTriggered: {
                    remindersModel.setICompletionStatus(listPage.item, "incomplete");
                    remindersModel.filter = "incomplete"
                }
            },
            ActionItem {
                title: "To-Do"
                imageSource: "asset:///images/todo.png"
                //ActionBar.placement: ActionBarPlacement.OnBar
                enabled: remindersModel.filter == "todo" ? false : true
                
                onTriggered: {
                    remindersModel.setICompletionStatus(listPage.item, "todo");
                    remindersModel.filter = "todo"
                }
            },
            ActionItem {
                title: "Edit"
                imageSource: "asset:///images/edit.png"
                ActionBar.placement: ActionBarPlacement.InOverflow
                
                onTriggered: {
                    editSheet.open();
                    editSheet.text = listText.text;
                    editSheet.index = listPage.title;
                }
            },
            DeleteActionItem {
                title: "Delete"
                ActionBar.placement: ActionBarPlacement.InOverflow
                onTriggered: {
                    //delete selected items
                    remindersModel.deleteListItem(listPage.item);
                    deletion.show();
                    nav.pop();
                }
            },
            InvokeActionItem {
                // share to any client that accepts it
                // allows more flexibility and options in the sharing overall
                title: "Share"
                ActionBar.placement: ActionBarPlacement.InOverflow
                
                query {
                    mimeType: "text/plain"
                    //invokeTargetId: "sys.bbm.sharehandler"
                    invokeActionId: "bb.action.SHARE"
                    data: "test"
                }
                //upon clicking the task is shared and so replaces data
                onTriggered: {
                    data = listPage.item.text;
                }
            }
        ]
        
        attachedObjects: [
            EditPage {
                id: editSheet
                title: "Edit"
                hintText: "Update task's description"
                
                onSaveListItem: {
 
                    remindersModel.editListItem(listPage.item, text, index);
                    
                    // Update the current item property data used in this Page to do this
                    // copy all values to temporary variable, copy text to it then transfer to list data.
                    var tempItem = listPage.item

                    tempItem.text = text
                    
                    tempItem.index = index
                    
                    listPage.item = tempItem
                    
                    listPage.title = tempItem.index
 
                }
            },
			SystemToast {
                id: deletion
                body: "Reminder deleted!"
            },
            ImagePaintDefinition {
                id: backgroundPaint
                imageSource: "asset:///images/Tile_scribble_light_256x256.amd"
                repeatPattern: RepeatPattern.XY
            }
        ]
    }
                
