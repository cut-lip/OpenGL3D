# OpenGL3D

## Write classes for 3D data visualization in OpenGL.

## The main class is a Canvas class which allows for abstraction of complex OpenGL functions through member functions.

This class is currently implemented to perform 2-D drawing and 2-D affine transformations, with 3D functionality coming next.

`glRotated()`, `glScaled()`, and `glTranslated()` are the affine trnsformation functions adapted for the Canvas class through the `Canvas::scale2D()`, `Canvas::translate2D(), and `Canvas::rotate2D()` functions.
