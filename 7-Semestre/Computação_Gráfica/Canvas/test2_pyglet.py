import pyglet

window = pyglet.window.Window()

#coordenadas iniciais da reta
x1 = 100
x2 = 200

y1 = 100
y2 = 200

def update(dt):
    global x1, x2, y1, y2
    print(x1, x2, y1, y2)
    if x1 == x2 and y1 <= y2:
        if x1 == x2:
            y1 += 1
        else:
            m = (y2 - y1) / (x2 - x1)
            b = y2 - m * x2
            y1 = int(m * x1 + b)



pyglet.clock.schedule_interval(update,1/90) #chama update a cada 60 vezes por segundo

@window.event
def on_draw():
    #window.clear()
    pyglet.graphics.draw(1,pyglet.gl.GL_POINTS,('v2i',(x1,y1)))

pyglet.app.run()
