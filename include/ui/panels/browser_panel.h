#ifndef BROWSER_PANEL_H
#define BROWSER_PANEL_H

#include "ui/ui_component.h"

#define MAX_FILEPATH_SIZE   128
#define FILE_HEIGHT         35

//! bounds field must be set 
typedef struct
{
    Rectangle   bounds;
    Vector2     offset;
    Rectangle   view;

    char            directory[MAX_FILEPATH_SIZE];
    FilePathList    files;
    int             content_height;
} UIBrowserPanelData;

UIComponent* createBrowserPanel(UIBrowserPanelData* browser_panal_data);
void destroyBrowserPanelData(void* browser_panal_data);

void updateBrowserPanel(struct UIComponent* browser_panel);
void drawBrowserPanel(struct UIComponent* browser_panel);

#endif // BROWSER_PANEL_H