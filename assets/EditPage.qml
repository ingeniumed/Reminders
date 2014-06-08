import bb.cascades 1.0
import bb.system 1.0
//import custom.lib 1.0
 
// sheet is used for editing and adding new items to the task list
Sheet {
    id: editSheet
    
    property alias title: addBar.title
    property alias hintText : itemText.hintText
    property alias text: itemText.text
    property alias index: itemIndex.text
    
    //trigger signal once changes are accepted
    signal saveListItem (string text, string index)
    
    Page {
        id: addPage
        
        attachedObjects: [
            SystemToast {
                id: emptySave
                body: "Warning: Empty reminder saved!"
            }
        ]
        
        titleBar: TitleBar {
            id: addBar
            title: "Add"
            visibility: ChromeVisibility.Visible
            
            dismissAction: ActionItem {
                title: "Cancel"
                onTriggered: {
                    //hide sheet to indicate cancellation
                    editSheet.close();
                }
            }
            
            acceptAction: ActionItem {
                title: "Save"
                onTriggered: {
                    //hide sheet again to indicate finished but also trigger save signal
                    if (itemText.text==""){ 
                        if (itemIndex.text==""){
                            emptySave.show();
                        }
                    } else {
                        emptySave.body = "Reminder saved!";
                        emptySave.show();
                    }
                    editSheet.close();
                    editSheet.saveListItem(itemText.text, itemIndex.text)
                    emptySave.show();
                }
            }
        }
        
        Container {
            id: editC
            property real margins: 40
            background: backgroundPaint.imagePaint
            
            topPadding: editC.margins
            leftPadding: editC.margins
            rightPadding: editC.margins
            
            layout: DockLayout {
            }

            attachedObjects: [
                  TextStyleDefinition {
                      id: editIndexStyle
                      base: SystemDefaults.TextStyleStyles.TitleText
                      fontSize: FontSize.Medium
                  },
                  TextStyleDefinition {
                      id: editTextStyle
                      base: SystemDefaults.TextStyleStyles.BodyText
                      fontStyle: FontStyle.Italic
                      fontSize: FontSize.Medium
                  },
                  ImagePaintDefinition {
                      id: backgroundPaint
                      imageSource: "asset:///images/Tile_scribble_light_256x256.amd"
                      repeatPattern: RepeatPattern.XY
                  }
              ]
              
            Container {
                
                TextField {
                    id: itemIndex
                    hintText: "Title of the reminder"
                    topMargin: editC.margins
                    bottomMargin: topMargin
                    
                    textStyle {
                        base: editIndexStyle.style
                    }
                    
                    horizontalAlignment: HorizontalAlignment.Fill
                }
                
                TextArea {
                    id: itemText
                    hintText: "What's the reminder?"
                    topMargin: editC.margins
                    bottomMargin: topMargin
                    preferredHeight: 250
                    maxHeight: 250
                    textStyle {
                        base: editTextStyle.style
                    }
                    
                    horizontalAlignment: HorizontalAlignment.Fill
                }
            }
        }
    }
}
