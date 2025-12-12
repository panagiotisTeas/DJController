#ifndef BROWSER_PANEL_H
#define BROWSER_PANEL_H

#include "ui/ui_component.h"

typedef struct
{
    Rectangle   bounds;
    Color       color;
} UIBrowserPanelData;

UIComponent* createBrowserPanel(UIBrowserPanelData* browser_panal_data);

void updateBrowserPanel(struct UIComponent* browser_panel);
void drawBrowserPanel(struct UIComponent* browser_panel);

#endif // BROWSER_PANEL_H