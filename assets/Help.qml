import bb.cascades 1.0

Page {
    id: helpPage
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        title: "    HELP"
    }
    ScrollView {
        horizontalAlignment: HorizontalAlignment.Fill
        verticalAlignment: VerticalAlignment.Fill
        
        scrollViewProperties {
            scrollMode: ScrollMode.Vertical
        }
    Container {
        attachedObjects: [
                  TextStyleDefinition {
                      id: answerTextStyle
                      base: SystemDefaults.TextStyleStyles.BodyText
                      fontStyle: FontStyle.Italic
                      fontSize: FontSize.Medium
                  },
                  TextStyleDefinition {
                      id: questionTextStyle
                      base: SystemDefaults.TextStyleStyles.BodyText
                      fontWeight: FontWeight.Bold
                      fontSize: FontSize.Medium
                  }
              ]
        layout: StackLayout {
        }
            Label {
                id: question1
                multiline: enabled
                textStyle {
                        base: questionTextStyle.style
                    }    
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "What do each of the filters mean?"
        }
            Label {
                id: answer1i
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "To-Do: I am going to procastinate on this task and do it later. Don't want to start on it now!!"  
            }
            Label {
                id: answer1ii
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "Incomplete: I started this task but I am not really done it. Better than procastinating on it!"  
            }
            Label {
                id: answer1iii
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "Completed: I am done this task! VICTORY IS MINE!"  
            }
            Label {
                id: question2
                multiline: enabled
                textStyle {
                        base: questionTextStyle.style
                    }    
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "What can I share my task with?"
        }
            Label {
                id: answer2
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "Any application really that accepts a String (sentence/word/letter)! It could be BBM or even Docs To Go"  
            }
            Label {
                id: question3
                multiline: enabled
                textStyle {
                        base: questionTextStyle.style
                    }    
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "What do you have in mind for the future?"
        }
            Label {
                id: answer3i
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "My primary goal is get notifications to work followed by integration with other cloud services such as Dropbox and Box.net!"  
            }
            Label {
                id: answer3ii
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "I also want to allow images to be attached to a task to better enhance it! Also follow my blog for more info: ingeniumed.tumblr.com!"  
            }
            Label {
                id: question4
                multiline: enabled
                textStyle {
                        base: questionTextStyle.style
                    }    
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "How can you be contacted for support/suggestions?"
        }
            Label {
                id: answer4
                multiline: enabled
                textStyle {
                        base: answerTextStyle.style
                    }
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "I can be reached at ingeniumed@outlook.com for support and suggestions!"  
            }
    }
}
}
