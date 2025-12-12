#ifndef UI_COMPONENT
#define UI_COMPONENT

#include "raylib/raylib.h"

typedef enum
{
    UI_PANEL = 0,
    UI_WIDGET
} ComponentType;

typedef enum
{
    PANEL_BROWSER = 0,
    PANEL_EFFECTS
} PanelType;

typedef enum
{
    WIDGET_BUTTON = 0,
    WIDGET_SLIDER
} WidgetType;

typedef union 
{
    PanelType   panel_type;
    WidgetType  widget_type;
} ElementType;

typedef struct UIComponent
{
    ComponentType   component_type;
    ElementType     element_type;

    void* component_data;

    struct UIComponent**    components;
    unsigned int            components_size;
    unsigned int            components_capacity;
    
    void (*update)(struct UIComponent*);
    void (*draw)(struct UIComponent*);
} UIComponent;

void addUIComponent(UIComponent* ui_component_parent, UIComponent* ui_component_child);
void removeUIComponent(UIComponent* ui_component_parent, UIComponent* ui_component_child);
void destroyUIComponent(UIComponent* ui_component);

#endif // UI_COMPONENT