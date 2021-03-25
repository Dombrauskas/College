import pyglet

#coordenadas iniciais da reta
p1 = [int(i) for i in input("Entre com as coordenadas de P1 x y: ").split()]
p2 = [int(i) for i in input("Entre com as coordenadas de P2 x y: ").split()]

dx = p2[0] - p1[0]
dy = p2[1] - p1[1]

i = p1[0]
y = p1[1]

reta = []

if dx == 0:
    for y in range(p1[1], p2[1]):
        reta.append(p1[0])
        reta.append(y)
elif dy == 0:
    for i in range(p1[0], p2[0]):
        reta.append(i)
        reta.append(p1[1])

# # x=x1 y=y1
# # dy=y1-y0
# # dx=x1-x0
# d = 2* dy- dx
# for i in range(1, dx):
#     # ligarPixel(x,y)
#     if d > 0:
#         y = y + 1
#         d = d - 2(dy-dx)
#     else:
#         d = d + 2dy
#         x = x + 1

elif dx > dy:
    d = 2 * dy - dx
    for i in range(dx):
        reta.append(i)
        reta.append(y)
        if d >= 0:
            d = d + 2 * (dy - dx)
            y += 1
        else:
            d = d + (2 * dy)
        i += 1
else:
    d = 2 * dx - dy
    for i in range(dy):
        reta.append(i)
        reta.append(y)
        if d >= 0:
            d = d + 2 * (dx - dy)
            i += 1
        else:
            d = d + (2 * dx)
        y += 1

print(reta)
window = pyglet.window.Window()

@window.event
def on_draw():
    global reta
    pyglet.graphics.draw(int(len(reta)/2),pyglet.gl.GL_POINTS,('v2i',reta))

pyglet.app.run()