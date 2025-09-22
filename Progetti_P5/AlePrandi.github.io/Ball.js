class Ball {
    constructor(x, y, r, colore) {
        this.position = createVector(x, y); // posizione vettoriale
        this.velocity = p5.Vector.random2D().mult(4); // velocità
        this.r = r; // raggio
        this.m = r * 0.1;
        this.colore = colore;
        this.classifica = 0;
        this.nGiocatori = 0;
        this.scommessa = 0;
        this.arrivato = false;
    }

    update() { // aggiorna la posizione
        this.position.add(this.velocity); 
    }
    
    checkBoundaryCollision() { // collisioni con il bordo dello schermo 
        if (this.position.x > width - this.r || this.position.x < this.r) {
            this.velocity.x *= -1;
        }
        if (this.position.y > height - this.r || this.position.y < this.r) {
            this.velocity.y *= -1;
        }
    }

    checkCollision(other) { // collisioni con le altre palle 
        let distanceVect = p5.Vector.sub(other.position, this.position);
        let distanceVectMag = distanceVect.mag();
        let minDistance = this.r + other.r;

        if (distanceVectMag < minDistance) {
            let distanceCorrection = (minDistance - distanceVectMag) / 2.0;
            let correctionVector = distanceVect.copy().normalize().mult(distanceCorrection);

            other.position.add(correctionVector);
            this.position.sub(correctionVector);

            let normal = distanceVect.copy().normalize();
            let relativeVelocity = p5.Vector.sub(other.velocity, this.velocity);
            let dotProduct = p5.Vector.dot(relativeVelocity, normal);
            let impulse = normal.mult(dotProduct);

            this.velocity.add(impulse.div(this.m));
            other.velocity.sub(impulse.div(other.m));
        }
    }

    display() { // mostra la palla sullo schermo 
        noStroke();
        fill(this.colore); // colore palla
        ellipse(this.position.x, this.position.y, this.r * 2, this.r * 2); // crea palla
    }
}