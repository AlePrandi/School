public class Punto {
    private float x;
    private float y;

    public Punto() {
        x = 0;
        y = 0;
    }

    public Punto(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public void setX(float x) {
            this.x = x;
    }

    public void setY(float y) {
        if (y >= 0)
            this.y = y;
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public float getDistanza(Punto p) {
        return (float) Math.sqrt(Math.pow(x - p.getX(), 2) + Math.pow(y - p.getY(), 2));  
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
