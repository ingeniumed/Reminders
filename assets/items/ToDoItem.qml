import bb.cascades 1.0

//list item component for all the items in the list
StandardListItem {
    id: listItem
    title: {
        " " + ListItemData.index
    }
    imageSpaceReserved: false
}