import bb.cascades 1.0

Page {
    id: creditsPage
    titleBar: TitleBar {
        id: titleBar
        visibility: ChromeVisibility.Visible
        title: "    CREDITS"
    }
    Container {
        attachedObjects: [
                  TextStyleDefinition {
                      id: editTextStyle
                      base: SystemDefaults.TextStyleStyles.BodyText
                      fontStyle: FontStyle.Italic
                      fontSize: FontSize.Medium
                  }
              ]
        layout: StackLayout {
        }
            Label {
                id: instruction0
                textStyle {
                        base: editTextStyle.style
                    }    
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                text: "TESTERS: "
                }
               Label {
                    id: instruction1
                    textStyle {
                        base: editTextStyle.style
                    }    
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    text: "            "
                }
                Label {
                    id: instruction2
                    textStyle {
                        base: editTextStyle.style
                    }    
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    text: "Bart Brewinski"
                }
                Label {
                    id: instruction3
                    textStyle {
                        base: editTextStyle.style
                    }    
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    text: "Monica Kochofar"
                }
                Label {
                    id: instruction4
                    textStyle {
                        base: editTextStyle.style
                    }    
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    text: "Zahraa Tamimi"
                }
    }
}
