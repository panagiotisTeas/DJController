#include "ui/panels/browser_panel.h"

#include "raylib/raygui.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

UIComponent* createBrowserPanel(UIBrowserPanelData* browser_panal_data)
{
    assert(!(browser_panal_data == NULL) && "browser_panal_data is NULL!\n");

    UIComponent* browser_panel = (UIComponent*)malloc(sizeof(UIComponent));

    TextCopy(browser_panal_data->directory, GetWorkingDirectory());
    browser_panal_data->files           = LoadDirectoryFiles(browser_panal_data->directory);
    browser_panal_data->content_height  = browser_panal_data->files.count * FILE_HEIGHT;

    browser_panal_data->view            = (Rectangle){0};
    browser_panal_data->offset          = (Vector2){0};

    browser_panel->component_type           = UI_PANEL;
    browser_panel->element_type.panel_type  = PANEL_BROWSER;
    browser_panel->component_data           = browser_panal_data;
    browser_panel->components_size          = 0;
    browser_panel->components_capacity      = 1;
    browser_panel->components               = (UIComponent**)malloc(browser_panel->components_capacity * sizeof(UIComponent));
    browser_panel->update                   = updateBrowserPanel;
    browser_panel->draw                     = drawBrowserPanel;
    browser_panel->destroyComponentData     = destroyBrowserPanelData;

    return browser_panel;
}

void destroyBrowserPanelData(void* browser_panal_data)
{
    UIBrowserPanelData* data = (UIBrowserPanelData*)browser_panal_data;

    UnloadDirectoryFiles(data->files);
    free(data);
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

    if(browser_panel->components != NULL)
    {
        for(unsigned int i = 0; i < browser_panel->components_size; i++)
        {
            browser_panel->components[i]->draw(browser_panel->components[i]);
        }
    }

    GuiScrollPanel(data->bounds, NULL, (Rectangle){0, 0, data->bounds.width, data->content_height}, &data->offset, &data->view);

    const float content_x = data->view.x + data->offset.x;
    const float content_y = data->view.y + data->offset.y;
    
    BeginScissorMode(data->view.x, data->view.y, data->view.width, data->view.height);
    {
        for(unsigned int i = 0; i < data->files.count; i++)
        {
            //* Directory
            if(!IsPathFile(data->files.paths[i]))
            {
                GuiButton((Rectangle){content_x, content_y + FILE_HEIGHT * (i + 1), data->bounds.width, FILE_HEIGHT}, GetFileName(data->files.paths[i]));
            }
            //* MP3 Files
            else if(IsPathFile(data->files.paths[i]) && IsFileExtension(data->files.paths[i], ".mp3"))
            {
                GuiButtonCustom((Rectangle){content_x, content_y + FILE_HEIGHT * (i + 1), data->bounds.width, FILE_HEIGHT}, GetFileName(data->files.paths[i]), Fade(LIGHTGRAY, 0.5f));
            }
            //* Other Files
            else
            {
                GuiButtonCustom((Rectangle){content_x, content_y + FILE_HEIGHT * (i + 1), data->bounds.width, FILE_HEIGHT}, GetFileName(data->files.paths[i]), Fade(LIGHTGRAY, 0.5f));
            }
        }
    }
    EndScissorMode();

    //TODO Make Custom UI Button Component
    GuiButton((Rectangle){data->view.x, data->view.y, data->bounds.width / 3, FILE_HEIGHT}, "Back");
    GuiButton((Rectangle){data->view.x + data->bounds.width / 3, data->view.y, data->bounds.width / 3, FILE_HEIGHT}, "Load");
    GuiButton((Rectangle){data->view.x + 2 * data->bounds.width / 3, data->view.y, data->bounds.width / 3, FILE_HEIGHT}, "Unload");

}