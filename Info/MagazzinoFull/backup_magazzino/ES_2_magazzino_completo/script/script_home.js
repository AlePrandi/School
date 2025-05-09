let url = "./magazzino.json"; // URL del JSON

// Funzione per pulire elementi per classe
function clearForClass(classe) {
    let elem = document.getElementsByClassName(classe);
    while (elem.length > 0) {
        elem[0].parentNode.removeChild(elem[0]);
    }
}

// Popola il contenitore delle card
let card_container = document.getElementsByClassName("card-container")[0]; // Accesso corretto al primo elemento
let sezioneRicercaPrincipale = document.getElementById('sezione-ricerca-principale');
let sezioneRicerca = document.getElementById('sezione-ricerca');
let datiJson = []; // Variabile globale per i dati
let datiProd = document.getElementById('datiProd');

fetch(url)
    .then(response => response.json()) // Richiamo la funzione json
    .then(dati => {
        datiJson = dati;
        console.log(datiJson); // Stampo l'oggetto creato dall'importazione del json

        // Funzione per creare una card
        function creaCard(riga) {
            let card = document.createElement('div');
            card.classList.add("card"); // Aggiungo la classe "card" per styling
            card.innerHTML = `
                <a class="card1" href="#">
                    <div class="caratteristiche">
                        <p>${riga.modelloNome}</p>
                        <p class="small">reparto: ${riga.reparto}<br>marca: ${riga.marca}</p>
                        <div class="go-corner">
                            <div class="go-arrow">→</div>
                        </div>
                    </div>
                </a>`;
            card.addEventListener('click', (event) => {
                event.preventDefault(); // Previene il comportamento predefinito del link
                mostraDettagli(riga); // Mostra i dettagli del prodotto
            });
            card_container.appendChild(card); // Appendo il nuovo elemento al container
        }

        // Creazione delle card per ogni elemento del JSON
        datiJson.forEach(riga => {
            creaCard(riga);
        });
    });

// Funzione per mostrare i dettagli del prodotto
function mostraDettagli(riga) {
    // Nasconde tutte le card piccole
    card_container.style.display = 'none';
    sezioneRicerca.style.display = 'none';
    sezioneRicercaPrincipale.style.display = 'none';
    clearForClass(card_container)

    // Nasconde la sezione di ricerca

    // Seleziona il contenitore per i dettagli
    datiProd.style.display = 'flex'; // Mostra il contenitore dei dettagli

    // Popola il contenitore dei dettagli con la struttura della card grande
    datiProd.innerHTML = `
        <div class="card-large-container">
            <div class="card-large">
                <label class="title-large">${riga.marca} ${riga.modelloNome}</label>
                <div class="steps-large">
                    <div class="step-large">
                        <div>
                            <span>DETTAGLI PRODOTTO</span>
                            <div class="details">
                                <span>Marca: </span>
                                <span class="editable" data-field="marca">${riga.marca}</span><br>
                                <span>Modello: </span>
                                <span class="editable" data-field="modelloNome">${riga.modelloNome}</span><br>
                                <span>Reparto: </span>
                                <span class="editable" data-field="reparto">${riga.reparto}</span><br>
                                <span>Tipo: </span>
                                <span class="editable" data-field="tipoProdotto">${riga.tipoProdotto}</span><br>
                                <span>Codice prodotto: </span>
                                <span class="editable" data-field="codiceProd">${riga.codiceProd}</span>
                            </div>
                        </div>
                        <div>
                            <span>DETTAGLI RESPONSABILE</span>
                            <div class="details">
                                <span>Nome:</span>
                                <span class="editable" data-field="Nominativo_responsabile">${riga.Nominativo_responsabile}</span><br>
                                <span>Telefono:</span>
                                <span class="editable" data-field="cell_resp">${riga.cell_resp}</span>
                            </div>
                        </div>
                        <div>
                            <span>DETTAGLI MAGAZZINO</span>
                            <div class="details">
                                <span>${riga.fornitore1}: </span>
                                <span class="editable" data-field="costo1">€${riga.costo1}</span><br>
                                <span>${riga.fornitore2}:</span>
                                <span class="editable" data-field="costo2">€${riga.costo2}</span><br>
                                <span>Quantità:</span>
                                <span class="editable" data-field="qt">${riga.qt} pz</span>
                            </div>
                        </div>
                        <div class="payments-large">
                            <span>AREA CLIENTI</span>
                            <div class="details">
                                <span>Subtotale:</span>
                                <span class="editable" data-field="prezzo">€${riga.prezzo}</span><br>
                                <span>IVA:</span>
                                <span class="editable" data-field="IVA">${riga.IVA}%</span>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="checkout-large">
                <div class="footer-large">
                    <label class="price-large">€${(riga.prezzo + riga.prezzo * riga.IVA / 100).toFixed(2)}</label>
                    <button class="checkout-btn" onclick="tornaIndietro()">Torna Indietro</button>
                    <button id="modificaBtn" class="checkout-btn">Modifica</button>
                </div>
            </div>
        </div>`;
}

// Funzione per tornare indietro
function tornaIndietro() {
    // Mostra di nuovo tutte le card piccole
    card_container.style.display = 'flex';

    // Ripristina la visualizzazione della sezione di ricerca
    datiProd.style.display = 'none';

    // Nasconde i dettagli del prodotto
}

// -- Inizio della sezione di ricerca --

// Selezioniamo gli elementi della pagina
let bottoneCerca = document.querySelector('.bottone-cerca');

// Variabili per la gestione della ricerca
let nome = document.getElementById("nome");
let cod = document.getElementById("codice");
let reparto = document.getElementById("reparto");
let marca = document.getElementById("marca");
let tipo = document.getElementById("tipo");
let cerca = document.getElementById("cerca");

// Mostra la sezione di ricerca quando si clicca il pulsante "Cerca"
bottoneCerca.addEventListener('click', () => {
    if (sezioneRicercaPrincipale.style.display && sezioneRicerca.style.display == 'none') {
        sezioneRicercaPrincipale.style.display = 'block'; // Mostra la sezione di ricerca
        sezioneRicerca.style.display = 'block'; // Mostra i div della sezione di ricerca
    } else {
        sezioneRicercaPrincipale.style.display = 'none'; // Nascondi la sezione di ricerca
        sezioneRicerca.style.display = 'none'; // Nascondi i div della sezione di ricerca
    }
    datiProd.style.display = 'none';
    clearForClass(datiProd);

    // Itero su ciascun oggetto nel JSON per ottenere il reparto
    datiJson.forEach(riga => {
        const rep = riga.reparto;

        // Controllo se il reparto esiste già nella select
        let presente = false;
        for (let i = 0; i < reparto.options.length; i++) {
            if (reparto.options[i].value === rep) {
                presente = true;
                break;
            }
        }

        // Se il reparto non esiste nella select, lo aggiungo
        if (!presente) {
            const option = document.createElement('option');
            option.value = rep;
            option.textContent = rep.charAt(0).toUpperCase() + rep.slice(1);
            reparto.appendChild(option);
        }
    });
});

// Funzionalità di ricerca
cerca.addEventListener("click", function (e) {
    e.preventDefault();

    datiProd.style.display = 'none';

    // Nascondi tutte le card
    let cards = document.getElementsByClassName("card");
    for (let i = 0; i < cards.length; i++) {
        cards[i].style.display = "none";
    }

    // Filtra i dati in base ai criteri di ricerca
    datiJson.forEach(riga => {
        let filtro = true;

        // Verifico solo i campi che sono stati riempiti dall'utente
        if (nome.value && riga.modelloNome.toLowerCase() !== nome.value.toLowerCase()) filtro = false;
        if (cod.value && riga.codiceProd.toLowerCase() !== cod.value.toLowerCase()) filtro = false;
        if (reparto.value && riga.reparto.toLowerCase() !== reparto.value.toLowerCase()) filtro = false;
        if (marca.value && riga.marca.toLowerCase() !== marca.value.toLowerCase()) filtro = false;
        if (tipo.value && riga.tipoProdotto.toLowerCase() !== tipo.value.toLowerCase()) filtro = false;

        // Se i filtri corrispondono, mostra la card
        if (filtro) {
            for (let i = 0; i < cards.length; i++) {
                if (cards[i].querySelector(".caratteristiche p").textContent === riga.modelloNome) {
                    cards[i].style.display = "block";
                    break;
                }
            }
        }
    });
});