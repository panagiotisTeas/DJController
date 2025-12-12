#include "ui/ui_component.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void addUIComponent(UIComponent* ui_component_parent, UIComponent* ui_component_child)
{
    assert(!(ui_component_parent == NULL) && "ui_component_parent is NULL!\n");
    assert(!(ui_component_child == NULL) && "ui_component_child is NULL!\n");

    if (ui_component_parent->components_size == ui_component_parent->components_capacity)
    {
        ui_component_parent->components_capacity *= 2;
        ui_component_parent->components = (UIComponent**)realloc(ui_component_parent->components, ui_component_parent->components_capacity * sizeof(UIComponent*));
        if(ui_component_parent->components == NULL)
        {
            fprintf(stderr, "Memory Reallocation Failed! UIComponent child was not added to UIComponent parent!\n");
            return;
        }
    }

    ui_component_parent->components[ui_component_parent->components_size++] = ui_component_child;
}

//! WARNING: `removeUIComponent` does not `free()` the child, It is the users responsibility to `free()` it.
void removeUIComponent(UIComponent* ui_component_parent, UIComponent* ui_component_child)
{
    assert(!(ui_component_parent == NULL) && "ui_component_parent is NULL!\n");
    assert(!(ui_component_child == NULL) && "ui_component_child is NULL!\n");

    for(unsigned int i = 0; i < ui_component_parent->components_size; i++)
    {
        if(ui_component_parent->components[i] == ui_component_child)
        {
            for(unsigned int j = i; j < ui_component_parent->components_size - 1; j++)
            {
                ui_component_parent->components[j] = ui_component_parent->components[j + 1];
            }
            ui_component_parent->components_size--;
            return;
        }
    }

    fprintf(stderr, "UIComponent parent does not contain UIComponent child! Nothing was removed!\n");
}

void destroyUIComponent(UIComponent* ui_component)
{
    assert(!(ui_component == NULL) && "ui_component is NULL!\n");

    if (ui_component->component_data != NULL)
    {
        free(ui_component->component_data);
    }

    for(unsigned int i = 0; i < ui_component->components_size; i++)
    {
        destroyUIComponent(ui_component->components[i]);
    }

    free(ui_component->components);
    free(ui_component);
}