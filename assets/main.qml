// Share button for exporting all the data via NFC so another app in another platform can use
// it for getting the data. Cross platform functionality possibility with this!

import bb.cascades 1.0
//import custom.lib 1.0
 
//import the model set in the app as a constructor for the entire thing to work
import com.app.appmodel 1.0
import "items"

NavigationPane {
    id: nav
    Page {
        id: remindersListPage
        titleBar: TitleBar {
            id: title
            title: "    REMINDERS"
            visibility: ChromeVisibility.Visible
        }
        
        Container {
            background: backgroundPaint.imagePaint
            topPadding: 20

            // The segmented control decides which filter should be set on the datamodel
            SegmentedControl {
                id: segmented
                
                horizontalAlignment: HorizontalAlignment.Center
                
                Option {
                    text: "To-Do"
                    value: "todo"
                }
                
                Option {
                    text: "Incomplete"
                    value: "incomplete"
                }
                
                Option {
                    text: "Completed"
                    value: "completed"
                }
                
                onSelectedValueChanged: {
                    // When a new Option is selected the dataModel of the ListView, the remindersModels
                    // filter is set and the list is repopulated and the selectedText property is updated.

                    remindersModel.filter = selectedValue;
                    
                    if(selectedValue() != "todo") {
                        remindersListPage.actionBarVisibility = ChromeVisibility.Hidden
                    } else {
                        remindersListPage.actionBarVisibility = ChromeVisibility.Visible
                    }
                }
            }
            
            ListView {
                id: remindersList
                
                // the data model definied in attached object
                dataModel: remindersModel

                attachedObjects: [
                    //the model is private so used as an attached object
                    AppModel {
                        id: remindersModel
                        
                        //json path with initial data
                        jsonAssetPath: "app/native/assets/models/reminders.json"
                        
                        filter: "todo"
                    }
                ]
                
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                
                listItemComponents: [
                    ListItemComponent {
                        type: "todo"
                        ToDoItem {
                            //items/ToDoItem.qml basically executed here
                        }
                    }
                ]
                
                onTriggered: {
                    //navigate to the edit page where the task can be edited as per the users wishes
                    var chosenItem = dataModel.data(indexPath);
                    var page = remindersPage.createObject();
                    
                    //set properties of page and then push the damn thing
                    page.item = chosenItem;
                    page.remindersModel = remindersModel;
                    page.title = chosenItem.index;
                    page.control = segmented
                    nav.push(page);
                }
                
                function itemType(data, indexPath) {
                    return "todo";
                }
            }
        }
        
        attachedObjects: [
            EditPage {
                //adding new items sheet
                id: addNew
                onSaveListItem: {
                    remindersModel.addListItem(text,index);
                    //remindersList.scrollTo(ScrollPosition.Top, ScrollAnimation.Default);
                }
            },
            ImagePaintDefinition {
                id: backgroundPaint
                imageSource: "asset:///images/Tile_scribble_light_256x256.amd"
                repeatPattern: RepeatPattern.XY
            },
            ComponentDefinition {
                id: remindersPage
                source: "RemindersPage.qml"
            },
            ComponentDefinition {
                id: helpPage
                source: "Help.qml"
            },
            ComponentDefinition {
                id: creditsPage
                source: "Credits.qml"
            }
        ]
        
        actions: [
            ActionItem {
                //add action item for adding to the list
                title: "Add"
                imageSource: "asset:///images/add.png"
                //ActionBar.placement: ActionBarPlacement.OnBar
                
                //check if list is full
                enabled: !remindersModel.listIsFull;
                
                onTriggered: {
                    addNew.open();
                    addNew.text = "";
                }
            },
            ActionItem {
                //add action item for going to the help page
                title: "Help"
                imageSource: "asset:///images/help.png"
                ActionBar.placement: ActionBarPlacement.InOverflow

                onTriggered: {
                    var page = helpPage.createObject();
                    nav.push(page);
                }
            },
            ActionItem {
                //add action item for credits page
                title: "Credits"
                imageSource: "asset:///images/credits.png"
                ActionBar.placement: ActionBarPlacement.InOverflow

                onTriggered: {
                    var page = creditsPage.createObject();
                    nav.push(page);
                }
            }
        ]
    }
        
        onCreationCompleted: {
            //notify cascades app is omnidirectional 
            OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
        }
        
        onTopChanged: {
            if (remindersModel.filter=="todo")
            {
                segmented.setSelectedIndex(0)
            }else if (remindersModel.filter=="incomplete") {
                segmented.setSelectedIndex(1)
            }else{
                segmented.setSelectedIndex(2)
            }
        }
        
        onPopTransitionEnded: {
            page.destroy();
        }
        
}