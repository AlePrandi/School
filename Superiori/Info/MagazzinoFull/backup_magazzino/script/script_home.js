let url = "./magazzino.json"; // URL del JSON
let nuovoBtn = document.getElementById("nuovoBtn");
let nuovoRepartoBtn = document.getElementById("nuovorepartoBtn");
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
            nuovoRepartoBtn.style.display = 'none';
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

    let modificaBtn = document.getElementById("modificaBtn");

    modificaBtn.addEventListener("click", function () {
        if (modificaBtn.textContent === "Modifica") {
            let editables = document.querySelectorAll(".editable");

            editables.forEach(span => {
                let fieldValue = span.textContent.trim();
                let input = document.createElement("input");
                input.value = fieldValue.replace("€", "").replace("%", "").replace(" pz", "");
                input.dataset.field = span.dataset.field;
                span.parentNode.replaceChild(input, span);
            });

            modificaBtn.textContent = "Salva modifiche";

            let eliminaButton = document.createElement("button");
            eliminaButton.textContent = "Elimina";
            eliminaButton.classList.add("checkout-btn");
            eliminaButton.style.marginLeft = "10px";
            modificaBtn.parentNode.appendChild(eliminaButton);

            eliminaButton.addEventListener("click", async function () {
                let index = datiJson.findIndex(riga => riga.codiceProd === currentProductData.codiceProd);

                datiJson.splice(index, 1);

                datiProd.innerHTML = "";
                if (datiJson !== null) {
                    const jsonFile = new File([JSON.stringify(datiJson)], "magazzino.json", {
                        type: "application/json",
                    });

                    const fileHandle = await window.showSaveFilePicker({
                        suggestedName: jsonFile.name,
                        types: [
                            {
                                description: "JSON file",
                                accept: { "application/json": [".json"] },
                            },
                        ],
                    });

                    const writableStream = await fileHandle.createWritable();
                    await writableStream.write(jsonFile);
                    await writableStream.close();

                    console.log("File saved successfully!");
                } else {
                    alert("Dati non corretti o nulli.");
                }
            });
        } else {
            let inputs = document.querySelectorAll("input[data-field]");
            let updatedData = {};

            inputs.forEach(input => {
                let span = document.createElement("span");
                span.classList.add("editable");
                span.dataset.field = input.dataset.field;

                if (input.dataset.field === "prezzo" || input.dataset.field === " costo1" || input.dataset.field === "costo2") {
                    span.textContent = "€" + input.value;
                } else if (input.dataset.field === "IVA") {
                    span.textContent = input.value + "%";
                } else if (input.dataset.field === "qt") {
                    span.textContent = input.value + " pz";
                } else {
                    span.textContent = input.value;
                }

                input.parentNode.replaceChild(span, input);

                if (input.dataset.field === "prezzo" || input.dataset.field === "IVA") {
                    updatedData[input.dataset.field] = parseFloat(input.value.replace("€", "").replace("%", ""));
                } else {
                    updatedData[input.dataset.field] = input.value;
                }
            });

            Object.keys(updatedData).forEach((key) => {
                currentProductData[key] = updatedData[key];
            });

            let prezzo = parseFloat(currentProductData.prezzo);
            let iva = parseFloat(currentProductData.IVA);
            let prezzoConIvaSpan = document.querySelector(".price");

            prezzoConIvaSpan.textContent = "€" + (prezzo + (prezzo * iva / 100)).toFixed(2);

            modificaBtn.textContent = "Modifica";
        }
    });

    let salvaButton = document.createElement("button");
    salvaButton.id = "salvaButton";
    salvaButton.textContent = "Salva modifiche e scarica file";
    salvaButton.classList.add("salva-btn");
    datiProd.appendChild(salvaButton);

    salvaButton.addEventListener("click", async () => {
        if (datiJson !== null) {
            const jsonFile = new File([JSON.stringify(datiJson)], "magazzino.json", {
                type: "application/json",
            });

            const fileHandle = await window.showSaveFilePicker({
                suggestedName: jsonFile.name,
                types: [
                    {
                        description: "JSON file",
                        accept: { "application/json": [".json"] },
                    },
                ],
            });

            const writableStream = await fileHandle.createWritable();
            await writableStream.write(jsonFile);
            await writableStream.close();

            console.log("File saved successfully!");
        } else {
            alert("Dati non corretti o nulli.");
        }
    });
}

nuovoRepartoBtn.addEventListener("click", function (e) {
    e.preventDefault();
    // Creazione del nuovo input dinamico con innerHTML
    const nuovoRepartoInputContainer = document.createElement("div");
    nuovoRepartoInputContainer.innerHTML = `
        <input type="text" id="nuovoRepartoInput" class="nuovo-reparto-input" placeholder="Inserisci il nuovo reparto">
        <button class="add" id="aggiungi_prod">add</button>
        `;
    document.body.appendChild(nuovoRepartoInputContainer);

    let nuovoRepartoInput = document.getElementById(`nuovoRepartoInput`);
    let addButton = document.getElementById('aggiungi_prod');

    addButton.addEventListener("click", function (e) {
        let newReparto = nuovoRepartoInput.value.trim();
    
        if (newReparto !== "") {
            let existingReparti = datiJson.map(riga => riga.reparto); 
            if (!existingReparti.includes(newReparto)) {
                let repartoSelect = document.getElementById("repartoSelect"); // repartoSelect should exist in HTML

                let repartiUnivoci = new Set(datiJson.map(riga => riga.reparto));

                repartiUnivoci.add(newReparto);

                repartoSelect.innerHTML = "";

                repartiUnivoci.forEach(reparto => {
                    const option = document.createElement("option");
                    option.textContent = reparto;
                    repartoSelect.appendChild(option);
                });
    
                datiJson.push({ reparto: newReparto });

                nuovoRepartoInputContainer.style.display = 'none';
            } else {
                alert("Reparto già presente");
            }
        } else {
            alert("Inserisci il nome del reparto");
        }
    });
});

nuovoBtn.addEventListener("click", function (e) {
    nuovoRepartoBtn.style.display = "block";
    e.preventDefault();
    card_container.style.display = "none";
    clearForClass("datiProd");
    datiProd.innerHTML = `
            <div class="card-large-container">
                <div class="card-large">
                    <label class="title-large">Nuovo Prodotto</label>
                    <div class="steps-large">
                        <div class="step-large">
                            <div>
                                <span>DETTAGLI PRODOTTO</span>
                                <div class="details">
                                    <span>Reparto: </span>
                                    <select id="repartoSelect"></select><br>
                                    <span>Marca: </span>
                                    <input type="text" id="marca"><br>
                                    <span>Modello: </span>
                                    <input type="text" id="modelloNome"><br>
                                    <span>Tipo: </span>
                                    <input type="text" id="tipoProdotto"><br>
                                    <span>Codice prodotto: </span>
                                    <input type="text" id="codiceProd">
                                </div>
                            </div>
                            <div>
                                <span>DETTAGLI RESPONSABILE</span>
                                <div class="details">
                                    <span>Nome:</span>
                                    <input type="text" id="Nominativo_responsabile"><br>
                                    <span>Telefono:</span>
                                    <input type="text" id="cell_resp">
                                </div>
                            </div>
                            <div>
                                <span>DETTAGLI MAGAZZINO</span>
                                <div class="details">
                                    <span>Fornitore 1:</span>
                                    <input type="text" id="fornitore1"><br>
                                    <span>Costo 1 :</span>
                                    <input type="text" id="costo1"><br>
                                    <span>Fornitore 2:</span>
                                    <input type="text" id="fornitore2"><br>
                                    <span>Costo 2:</span>
                                    <input type="text" id="costo2"><br>
                                    <span>Quantità:</span>
                                    <input type="text" id="qt">
                                </div>
                            </div>
                            <div class="payments-large">
                                <span>AREA CLIENTI</span>
                                <div class="details">
                                    <span>Prezzo:</span>
                                    <input type="text" id="prezzo"><br>
                                    <span>IVA:</span>
                                    <input type="text" id="IVA">
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="checkout-large">
                        <div class="footer-large">
                            <label class="price-large">€0.00</label>
                            <button class="checkout-btn" id="salvaBtn">Salva</button>
                        </div>
                    </div>
                </div>
            </div>
        `;

    let repartoSelect = document.getElementById("repartoSelect");

    let repartiUnivoci = new Set();

    datiJson.forEach(riga => {
        repartiUnivoci.add(riga.reparto);
    });

    repartiUnivoci.forEach(reparto => {
        const option = document.createElement("option");
        option.textContent = reparto;
        repartoSelect.appendChild(option);
    });

    let salvaButton = document.getElementById("salvaBtn");

    salvaButton.addEventListener("click", async function () {
        let nuovoProdotto = {
            codiceProd: document.getElementById("codiceProd").value,
            reparto: document.getElementById("reparto").value,
            tipoProdotto: document.getElementById("tipoProdotto").value,
            marca: document.getElementById("marca").value,
            modelloNome: document.getElementById("modelloNome").value,
            qt: parseInt(document.getElementById("qt").value),
            prezzo: parseFloat(document.getElementById("prezzo").value),
            Nominativo_responsabile: document.getElementById("Nominativo_responsabile").value,
            cell_resp: document.getElementById("cell_resp").value,
            fornitore1: document.getElementById("fornitore1").value,
            costo1: parseFloat(document.getElementById("costo1").value),
            fornitore2: document.getElementById("fornitore2").value,
            costo2: parseFloat(document.getElementById("costo2").value),
            IVA: parseInt(document.getElementById("IVA").value),
        };

        datiJson.push(nuovoProdotto);

        let datiProdInner = `
                <div class="card-large-container">
                    <div class="card-large">
                        <label class="title-large">${nuovoProdotto.marca} ${nuovoProdotto.modelloNome}</label>
                        <div class="steps-large">
                            <div class="step-large">
                                <div>
                                    <span>DETTAGLI PRODOTTO</span>
                                    <div class="details">
                                        <span>Marca: </span>
                                        <span class="editable" data-field="marca">${nuovoProdotto.marca}</span>
                                        <span>Modello: </span>
                                        <span class="editable" data-field="modelloNome">${nuovoProdotto.modelloNome}</span>
                                        <span>Tipo: </span>
                                        <span class="editable" data-field="tipoProdotto">${nuovoProdotto.tipoProdotto}</span>
                                        <span>Codice prodotto: </span>
                                        <span class="editable" data-field="codiceProd">${nuovoProdotto.codiceProd}</span>
                                    </div>
                                </div>
                                <div>
                                    <span>DETTAGLI RESPONSABILE</span>
                                    <div class="details">
                                        <span>Nome:</span>
                                        <span class="editable" data-field="Nominativo_responsabile">${nuovoProdotto.Nominativo_responsabile}</span>
                                        <span>Telefono:</span>
                                        <span class="editable" data-field="cell_resp">${nuovoProdotto.cell_resp}</span>
                                    </div>
                                </div>
                                <div>
                                    <span>DETTAGLI MAGAZZINO</span>
                                    <div class="details">
                                        <span>${nuovoProdotto.fornitore1}: </span>
                                        <span class="editable" data-field="costo1">€${nuovoProdotto.costo1}</span>
                                        <span>${nuovoProdotto.fornitore2}: </span>
                                        <span class="editable" data-field="costo2">€${nuovoProdotto.costo2}</span>
                                        <span>Quantità: </span>
                                        <span class="editable" data-field="qt"> ${nuovoProdotto.qt} pz</span>
                                    </div>
                                </div>
                                <div class="payments-large">
                                    <span>AREA CLIENTI</span>
                                    <div class="details">
                                        <span>Subtotale:</span>
                                        <span class="editable" data-field="prezzo">€${nuovoProdotto.prezzo}</span>
                                        <span>IVA:</span>
                                        <span class="editable" data-field="IVA">${nuovoProdotto.IVA}%</span>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="checkout-large">
                        <div class="footer-large">
                            <label class="price-large">€${parseFloat(nuovoProdotto.prezzo) + parseFloat(nuovoProdotto.prezzo) * parseFloat(nuovoProdotto.IVA) / 100}</label>
                            <button class="checkout-btn" id="modificaBtn">Modifica</button>
                        </div>
                    </div>
                </div>
            `;

        datiProd.innerHTML = datiProdInner;

        const jsonFile = new File([JSON.stringify(datiJson)], "magazzino.json", {
            type: "application/json",
        });

        const fileHandle = await window.showSaveFilePicker({
            suggestedName: jsonFile.name,
            types: [
                {
                    description: "JSON file",
                    accept: { "application/json": [".json"] },
                },
            ],
        });

        const writableStream = await fileHandle.createWritable();
        await writableStream.write(jsonFile);
        await writableStream.close();

        console.log("File saved successfully!");
    });
});


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
let bottoneCerca = document.getElementById('bottone-cerca');

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
    
    nuovoRepartoBtn.style.display = "none";
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
