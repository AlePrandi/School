let url = "./magazzino2024.json"
let nome = document.getElementById("nome")
let cod = document.getElementById("codice")
let reparto = document.getElementById("reparto")
let marca = document.getElementById("marca")
let tipo = document.getElementById("tipo")
let cerca = document.getElementById("cerca")
const datiProd = document.getElementById("datiProd")

cerca.addEventListener("click", function (e) {
    e.preventDefault()
    clearForClass("prod")
    
    fetch(url)
        .then(response => response.json())
        .then(dati => {
            let trovato = false

            dati.forEach(riga => {
                let filtro = true
                // Verifico solo i campi che sono stati riempiti dall'utente
                if (nome.value && riga.modelloNome !== nome.value) filtro = false
                if (cod.value && riga.codiceProd !== cod.value) filtro = false
                if (reparto.value && riga.reparto !== reparto.value) filtro = false
                if (marca.value && riga.marca !== marca.value) filtro = false
                if (tipo.value && riga.tipoProdotto !== tipo.value) filtro = false

                if (filtro) {
                    console.log(riga)
                    trovato = true
                    datiProd.innerHTML += `<div class="prod">
                        <h2>${riga.modelloNome}</h2>
                        <p>Codice: ${riga.codiceProd}<br>
                           Reparto: ${riga.reparto}<br>
                           Tipo Prodotto: ${riga.tipoProdotto}<br>
                           Marca: ${riga.marca}<br>
                           Quantità: ${riga.qt}<br>
                           Prezzo: €${riga.prezzo}<br>
                           Nominativo Responsabile: ${riga.Nominativo_responsabile}<br>
                           Cellulare Responsabile: ${riga.cell_resp}<br>
                           Fornitore 1: ${riga.fornitore1} - Costo: €${riga.costo1}<br>
                           Fornitore 2: ${riga.fornitore2} - Costo: €${riga.costo2}<br>
                           IVA: ${riga.IVA}%</p>
                        </div>
                    `
                }
            })

            if (!trovato) {
                datiProd.innerHTML = '<div class="prod"><p style="color: red;">Errore: Prodotto non trovato</p></div>'
                
            }
        })
})

function clearForClass(classe) {
    let elems = document.getElementsByClassName(classe)
    while (elems.length > 0) {
        elems[0].parentNode.removeChild(elems[0])
    }
}
