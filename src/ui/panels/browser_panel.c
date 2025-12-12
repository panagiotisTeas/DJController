#include "ui/panels/browser_panel.h"

#include "raylib/raygui.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

UIComponent* createBrowserPanel(UIBrowserPanelData* browser_panal_data)
{
    assert(!(browser_panal_data == NULL) && "browser_panal_data is NULL!\n");

    UIComponent* browser_panel = (UIComponent*)malloc(sizeof(UIComponent));

    browser_panel->component_type           = UI_PANEL;
    browser_panel->element_type.panel_type  = PANEL_BROWSER;
    browser_panel->component_data           = browser_panal_data;
    browser_panel->components_size          = 0;
    browser_panel->components_capacity      = 1;
    browser_panel->components               = (UIComponent**)malloc(browser_panel->components_capacity * sizeof(UIComponent));
    browser_panel->update                   = updateBrowserPanel;
    browser_panel->draw                     = drawBrowserPanel;

    return browser_panel;
}

void updateBrowserPanel(struct UIComponent* browser_panel)
{
    assert(!(browser_panel == NULL) && "browser_panel is NULL!\n");
    
    if(browser_panel->components != NULL)
    {
        for(unsigned int i = 0; i < browser_panel->components_size; i++)
        {
            browser_panel->components[i]->update(browser_panel->components[i]);
        }
    }
}

void drawBrowserPanel(struct UIComponent* browser_panel)
{
    assert(!(browser_panel == NULL) && "browser_panel is NULL!\n");

    UIBrowserPanelData* data = (UIBrowserPanelData*)browser_panel->component_data;
    DrawRectangle(data->bounds.x, data->bounds.y, data->bounds.width, data->bounds.height, data->color);

    if(browser_panel->components != NULL)
    {
        for(unsigned int i = 0; i < browser_panel->components_size; i++)
        {
            browser_panel->components[i]->draw(browser_panel->components[i]);
        }
    }
}