# Plan

This quickly documents what my general plan is.

Firstly, this is the plan for the classes.

```mermaidjs
classDiagram
    class Node {
        +T value
        +T* left
        +T* right

        +Node(T& input)
    }

    class PointNode {
        +vector~int~ position

        +PointNode(vector~int~ pos)
    }

    class Star {
        +float luminosity
        +float acceleration
        +bool visited
        
        +StarNode(vector~int~ pos)
    }

    Node <|-- PointNode : private inherit
    PointNode <|-- Star : public inherit
```

