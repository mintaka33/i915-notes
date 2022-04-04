import numpy as np
from OpenGL.GL import *
import glfw

glfw.init()
# creating a window size having 900 as width and 700 as height
window = glfw.create_window(900, 700, "PyOpenGL Triangle", None,None)
glfw.set_window_pos(window, 500, 300)
glfw.make_context_current(window)

vertices = [-0.5, -0.5,0.0,
             0.5, -0.5,0.0,
             0.0, 0.5,0.0]

v = np.array(vertices, dtype = np.float32)

# this will draw a colorless triangle
glEnableClientState(GL_VERTEX_ARRAY)
glVertexPointer(3, GL_FLOAT,0,v)

# this will set a color for your background
glClearColor(255, 180, 0, 0)

while not glfw.window_should_close(window):
    glfw.poll_events()
    glClear(GL_COLOR_BUFFER_BIT)
    glDrawArrays(GL_TRIANGLES,0,3)
    glfw.swap_buffers(window)

glfw.terminate()