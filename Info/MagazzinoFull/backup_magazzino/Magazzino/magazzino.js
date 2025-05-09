let url = "./magazzino.json";
let prod = document.getElementById("prod");
let cerca = document.getElementById("Cerca");
const datiProd = document.getElementById("datiProd");

cerca.addEventListener("click", function (e) {
    clearForClass("datiProd");
    e.preventDefault();
    fetch(url)
        .then(response => response.json())
        .then(dati => {
            let trovato = false;
            console.log(dati);

            dati.forEach(riga => {
                if (riga.codiceProd === prod.value) {
                    trovato = true;
                    datiProd.innerHTML = `
   <div class="container datiProd">
        <div class="card cart">
            <label class="title">${riga.marca} ${riga.modelloNome}</label>
            <div class="steps">
                <div class="step">
                    <div>
                        <span>DETTAGLI PRODOTTO</span>
                        <div class="details">
                        <span>Marca:   </span>
                        <span class="editable" data-field="marca">${riga.marca}</span>
                        <span>Modello: </span>
                        <span class="editable" data-field="modelloNome">${riga.modelloNome}</span>
                        <span>Reparto: </span>
                        <span class="editable" data-field="reparto">${riga.reparto}</span>
                        <span>Tipo: </span>
                        <span class="editable" data-field="tipoProdotto">${riga.tipoProdotto}</span>
                        <span>Codice prodotto: </span>
                        <span class="editable" data-field="codiceProd">${riga.codiceProd}</span>
                        </div>
                    </div>
                    <div>
                        <span>DETTAGLI RESPONSABILE</span>
                        <div class="details">
                        <span>Nome:</span>
                        <span class="editable" data-field="Nominativo_responsabile">${riga.Nominativo_responsabile}</span>
                        <span>Telefono:</span>
                        <span class="editable" data-field="cell_resp">${riga.cell_resp}</span>
                        </div>
                    </div>
                    <div>
                        <span>DETTAGLI MAGAZZINO</span>
                        <div class="details">
                        <span>${riga.fornitore1}: </span>
                        <span class="editable" data-field="costo1">  €${riga.costo1}</span>
                        <span>${riga.fornitore2}:</span>
                        <span class="editable" data-field="costo2">  €${riga.costo2}</span>
                        <span>Quantità:</span>
                        <span class="editable" data-field="qt"> ${riga.qt} pz</span>
                        </div>
                    </div>

        <div class="payments">
            <span>AREA CLIENTI</span>
            <div class="details">
                <span>Subtotale:</span>
                <span class="editable" data-field="prezzo">€${riga.prezzo}</span>
                <span>IVA:</span>
                <span class="editable" data-field="IVA">${riga.IVA}%</span>
            </div>
        </div>
    </div>
</div>
</div>

<div class="card checkout">
    <div class="footer">
        <label class="price">€${riga.prezzo + riga.prezzo * riga.IVA/100}</label>
        <button class="checkout-btn">Salva</button>
        <button id="modificaBtn" class="checkout-btn">Modifica</button>
    </div>
</div>
</div>
`;

                    // Aggiungi funzionalità per il pulsante "Modifica"
                    document.getElementById("modificaBtn").addEventListener("click", function () {
                        let editables = document.querySelectorAll(".editable");
                        editables.forEach(span => {
                            let fieldValue = span.textContent.trim();
                            let input = document.createElement("input");
                            input.value = fieldValue.replace("€", "").replace("%", "");
                            input.dataset.field = span.dataset.field;
                            span.parentNode.replaceChild(input, span);
                        });

                        // Cambia il pulsante "Modifica" in "Salva"
                        this.textContent = "Salva modifiche";
                        this.removeEventListener("click", arguments.callee);

                        // Aggiungi funzionalità di salvataggio
                        this.addEventListener("click", function () {
                            let inputs = document.querySelectorAll("input[data-field]");
                            inputs.forEach(input => {
                                let span = document.createElement("span");
                                span.classList.add("editable");
                                span.dataset.field = input.dataset.field;
                                span.textContent = input.value;
                                input.parentNode.replaceChild(span, input);
                            });

                            // Cambia il pulsante di nuovo in "Modifica"
                            this.textContent = "Modifica";
                        });
                    });
                }
            });

            if (!trovato) {
                let divErrore = document.createElement('div');
                divErrore.classList.add("error");
                divErrore.innerHTML = '<p style="color: red;">Errore: Prodotto non trovato</span>';
                datiProd.appendChild(divErrore);
            }
        });
});

function clearForClass(classe) {
    let elems = document.getElementsByClassName(classe);
    while (elems.length > 0) {
        elems[0].parentNode.removeChild(elems[0]);
    }
}
