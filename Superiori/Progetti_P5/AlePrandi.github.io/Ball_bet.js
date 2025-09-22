let DIM_PALLA = 10;
let matrix; // matrice per la mappa
let DIM_QUADRATO = 50;
let rows, cols; // righe e colonne della matrice
let traguardo; // immagine del traguardo 
let slowdownRate = 0.96; // tasso con cui rallenta quando arriva
let posArrivo = 0; // posizioni per la classifica

let defPausa;
let defRiprendi;
let TastoPausa;
let isPaused = false;
let tastoPausaX = 10;
let tastoPausaY = 5;
let dimTastoPausa = 80;

let TastoRiavvio;
let tastoRiavvioX = 1215;
let tastoRiavvioY = 15;
let dimTastoRiavvio = 60;
let numGiocatori;
let tutteArrivate = false;
let finitoTempo = false;
let squareCenter;
let selectLevelText;
let levelSelected;
let livello = 0;
let mostrato = false;

let balls = [];

let startTime;
let elapsedTime = 0;
let maxTime = 60000; // 1 minuto

function preload() {
    matrix = loadStrings("./livello1.csv");
    traguardo = loadImage("./img/traguardo.png");
    defPausa = loadImage("./img/Pausa.png");
    defRiprendi = loadImage("./img/Riprendi.png");
    TastoPausa = loadImage("./img/Pausa.png");
    TastoRiavvio = loadImage("./img/Riavvio.png");
}

function setup() {
    createCanvas(1287, 582);

    selectLevelText = createP('Seleziona il livello');
    selectLevelText.position(width / 2 - 70, height / 2 - 100);

    let buttonLivello1 = createButton('Livello 1');
    buttonLivello1.position(width / 2 - 50, height / 2 - 50);
    buttonLivello1.mousePressed(() => { livello = 1; selectLevel(livello); });

    let buttonLivello2 = createButton('Livello 2');
    buttonLivello2.position(width / 2 - 50, height / 2);
    buttonLivello2.mousePressed(() => { livello = 2; selectLevel(livello); });

    let buttonLivello3 = createButton('Livello 3');
    buttonLivello3.position(width / 2 - 50, height / 2 + 50);
    buttonLivello3.mousePressed(() => { livello = 3; selectLevel(livello); });

}

function selectLevel(level) {
    let levelFileName = `./livello${level}.csv`;
    matrix = loadStrings(levelFileName, () => {
        currentLevel = level;
        initializeGame();
        levelSelected = true;
        hideButtons();
        selectLevelText.remove();
    });
    background(255);
}

function hideButtons() {
    let buttons = document.getElementsByTagName('button');
    for (let button of buttons) {
        button.style.display = 'none';
    }
}

function initializeGame() {
    rows = matrix.length;
    cols = matrix[0].split(',').length;

    for (let i = 0; i < 4; i++) {
        let x = 50 + (i % 2) * 50;
        let y = 500 + Math.floor(i / 2) * 50;
        balls.push(new Ball(x, y, DIM_PALLA, ["red", "green", "blue", "yellow"][i]));
    }

    numGiocatori = parseInt(prompt("Inserisci il numero di giocatori:"));

    for (let i = 0; i < numGiocatori; i++) {
        let coloriMessage = "Colori delle palle:\n";
        for (let i = 0; i < balls.length; i++) {
            let b = balls[i];
            coloriMessage += "Palla " + (i + 1) + ", colore: " + b.colore + "\n";
        }
        alert(coloriMessage);

        let pallaScelta = parseInt(prompt("Giocatore " + (i + 1) + ", scegli il numero della palla su cui puntare (da 1 a 4):"));
        if (pallaScelta >= 1 && pallaScelta <= 4) {
            balls[pallaScelta - 1].nGiocatori += 1;
            let puntata = parseInt(prompt("Giocatore " + (i + 1) + ", inserisci la puntata:"));
            balls[pallaScelta - 1].scommessa = puntata;
        } else {
            alert("Il numero della palla deve essere compreso tra 1 e 4.");
            i--;
        }
    }

    startTime = millis();
}

function mouseClicked() {
    //tasto pausa
    if (mouseX >= tastoPausaX && mouseX <= tastoPausaX + dimTastoPausa && mouseY >= tastoPausaY && mouseY <= tastoPausaY + dimTastoPausa) {
        isPaused = !isPaused;
        if (isPaused) {
            TastoPausa = defRiprendi;
        } else {
            TastoPausa = defPausa;
        }
    }
    //tasto riavvia
    if (mouseX >= tastoRiavvioX && mouseX <= tastoRiavvioX + dimTastoRiavvio && mouseY >= tastoRiavvioY && mouseY <= tastoRiavvioY + dimTastoRiavvio) {
        window.location.reload();
    }
}

function mostraTempo() {
    let secondi = Math.floor(elapsedTime / 1000);
    textSize(32);
    textAlign(CENTER, TOP);
    fill(255); // Colore bianco
    text("Tempo: " + secondi, width / 2 - 50, 10);
}

function sfondo() {
    // setta il colore di sfondo
    if (!levelSelected || livello === 1) {
        background(255);
    } else {
        if (livello === 2) {
            background(205, 133, 63);
        } else {
            background(152, 255, 152);
        }
    }
}

function creaMappa() {
    for (let i = 0; i < rows; i++) {
        let values = matrix[i].split(',');
        for (let j = 0; j < cols; j++) {
            let x = j * DIM_QUADRATO;
            let y = i * DIM_QUADRATO;

            if (values[j] === '1') {
                fill(0);
                rect(x, y, DIM_QUADRATO, DIM_QUADRATO);
            }

            if (values[j] === '2') {
                image(traguardo, x, y, DIM_QUADRATO, DIM_QUADRATO);
            }
        }
    }

    image(TastoPausa, tastoPausaX, tastoPausaY, dimTastoPausa, dimTastoPausa);
    image(TastoRiavvio, tastoRiavvioX, tastoRiavvioY, dimTastoRiavvio, dimTastoRiavvio);
}

function draw() {
    sfondo();
    creaMappa();
    mostraTempo();

    // calcola il tempo trascorso
    if (!isPaused) {
        elapsedTime = millis() - startTime;
        if (elapsedTime >= maxTime) {
            isPaused = true;
            finitoTempo = true;
        }
    }

    if (!isPaused) {
        for (let i = 0; i < balls.length; i++) {
            let b = balls[i];
            b.update();
            b.display();
            b.checkBoundaryCollision(); // con i bordi dello schermo

            for (let j = 0; j < rows; j++) {
                let values = matrix[j].split(',');
                for (let k = 0; k < cols; k++) {
                    squareCenter = createVector(k * DIM_QUADRATO + DIM_QUADRATO / 2, j * DIM_QUADRATO + DIM_QUADRATO / 2);

                    if (values[k] === '1') {
                        let dx = b.position.x - squareCenter.x;
                        let dy = b.position.y - squareCenter.y;
                        let distance = dist(b.position.x, b.position.y, squareCenter.x, squareCenter.y);

                        distance -= DIM_PALLA + 1;

                        if (distance < DIM_QUADRATO / 2) {
                            let penetration = DIM_QUADRATO / 2 - distance;
                            let correction = createVector(dx, dy).setMag(penetration);
                            b.position.add(correction);

                            let velocityDir = b.velocity.copy().normalize();

                            if (dx * velocityDir.x + dy * velocityDir.y < 0) {
                                let normal = createVector(dx, dy).normalize();
                                let velocityCorrection = normal.mult(2 * b.velocity.dot(normal));
                                b.velocity.sub(velocityCorrection);
                            }
                        }
                    }
                    
                    //se tocca il traguardo
                    if (values[k] === '2') {
                        let distance = dist(b.position.x, b.position.y, squareCenter.x, squareCenter.y);

                        distance -= DIM_PALLA + 1;

                        if (distance < DIM_QUADRATO / 2) {
                            b.velocity.mult(slowdownRate);
                            b.classifica = posArrivo++;
                            b.arrivato = true;
                            if (posArrivo == balls.length) {
                                tutteArrivate = true;
                            }
                        }
                    }
                }
            }
            // collisioni con altre palle 
            for (let j = i + 1; j < balls.length; j++) {
                let otherBall = balls[j];
                b.checkCollision(otherBall);
            }
        }
    } else {
        for (let i = 0; i < balls.length; i++) {
            balls[i].display();
        }

        const moltiplicatori = [5, 3, 2, 0.5]; // moltiplicatori per ogni posizione

        if (tutteArrivate || finitoTempo) {

            function customSort(a, b) { // entrambe arrivate
                if (a.arrivato && b.arrivato) {
                    return a.classifica - b.classifica;
                } else if (a.arrivato && !b.arrivato) {
                    return -1; // Mette prima quella arrivata
                } else if (!a.arrivato && b.arrivato) {
                    return 1; // Mette prima quella non arrivata
                } else {
                    let distanzaA = dist(a.position.x, a.position.y, squareCenter.x, squareCenter.y);
                    let distanzaB = dist(b.position.x, b.position.y, squareCenter.x, squareCenter.y);
                    return distanzaA - distanzaB;
                }
            }

            balls.sort(customSort); // ordina in base alla classifica e alla distanza dal traguardo

            for (let i = 0; i < balls.length; i++) {
                let b = balls[i];
                if (b.arrivato) {
                    b.scommessa *= moltiplicatori[i] / b.nGiocatori;
                } else {
                    let distanza = dist(b.position.x, b.position.y, squareCenter.x, squareCenter.y);
                    b.scommessa *= (100 / distanza) / b.nGiocatori;
                    b.scommessa = Math.max(b.scommessa, 0);
                }
            }

            if (!mostrato) {
                let classificaMessage = "Classifica delle palle \nVincita per ogni giocatore: \n";
                for (let i = 0; i < balls.length; i++) {
                    let b = balls[i];
                    let scommessa;
                    if (b.scommessa != 0) {
                        scommessa = b.scommessa.toFixed(2);
                    }else{
                        scommessa = b.scommessa;
                    }
                    classificaMessage += (i + 1) +"°a   Palla " + b.colore + ": vincita: " + scommessa + "\n";
                }

                alert(classificaMessage);
                mostrato = true;
            }
        }
    }
}