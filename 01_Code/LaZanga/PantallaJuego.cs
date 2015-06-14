using Microsoft.Xna.Framework;
using TomShane.Neoforce.Controls;
using Microsoft.Xna.Framework.Graphics;

namespace LaZanga
{
    class PantallaJuego : Pantalla
    {
        private MonitorMesa monitorMesa;
        private Label labelTriunfos;
        private Label labelTriunfosTítulo;
        private Label labelQuiénTriunfa;
        private Label labelQuiénTriunfaTítulo;
        private Label labelPróximoMano;
        private Label labelPróximoManoTítulo;
        private Label labelSePidióTítulo;
        private CheckBox checkBoxSolo;
        private CheckBox checkBoxCinco;
        private CheckBox checkBoxTodas;
        private TextBox textBoxLog;
        private Button botónComenzar;
        private Button botónSalir;
        private SelectorCarta[] selectoresAbajo;
        private SelectorCarta[] selectoresDerecha;
        private SelectorCarta[] selectoresArriba;
        private SelectorCarta[] selectoresIzquierda;
        private Button botónJuego;
        private Button botónPaso;
        private Button botónMeVoySolo;
        private Button botónVayaSolo;
        private Button botónVayaUsted;
        private Button botónRechazoZanga;
        private Button botónPidoCinco;
        private Button botónPidoTodas;
        private Button botónBastos;
        private Button botónCopas;
        private Button botónEspadas;
        private Button botónOros;
        private Panel panelZonaControl;

        public PantallaJuego(Manager manager, GraphicsDeviceManager graphics, MouseEventHandler handlerSalir)
            : base(manager)
        {
            // Calculamos el rectángulo de la pantalla (ventana de windows).
            Rectangle rectPantalla = new Rectangle(0, 0, graphics.PreferredBackBufferWidth, graphics.PreferredBackBufferHeight);

            // Calculamos el rectángulo de la zona de juego y de la zona de control.
            Rectangle rectZonaJuego = new Rectangle(0, 0, rectPantalla.Height, rectPantalla.Height);
            Rectangle rectZonaControl = new Rectangle(rectZonaJuego.Width, 0, rectPantalla.Width - rectZonaJuego.Width, rectPantalla.Height);         

            // Calculamos el rectángulo de la monitorMesa.
            Size tamañoMesa = new Size(rectZonaJuego.Width * 75 / 100, rectZonaJuego.Height * 75 / 100);
            Point esquinaIzquierdaMesa = new Point(rectZonaJuego.Center.X - tamañoMesa.Width / 2, rectZonaJuego.Center.Y - tamañoMesa.Height / 2);
            Rectangle rectMesa = new Rectangle(esquinaIzquierdaMesa.X, esquinaIzquierdaMesa.Y, tamañoMesa.Width, tamañoMesa.Height);

            // Calculamos los rectángulos de los slots de la zona de control.
            Size tamañoSlotControl = new Size(rectZonaControl.Width, rectZonaControl.Height / 6);
            Rectangle[] rectSlots = new Rectangle[6];
            for (int i = 0; i < rectSlots.Length; i++)
            {
                Point EsquinaIzquierdaSlot = new Point(rectZonaControl.Left, i * tamañoSlotControl.Height);
                rectSlots[i] = new Rectangle(EsquinaIzquierdaSlot.X, EsquinaIzquierdaSlot.Y, tamañoSlotControl.Width, tamañoSlotControl.Height);
            }

            // Slot de triunfos.
            Rectangle rectSlotTriunfos = rectSlots[0];
            Rectangle rectSlotLabelTriunfosTítulo = new Rectangle(rectSlotTriunfos.Left, rectSlotTriunfos.Top, rectSlotTriunfos.Width, rectSlotTriunfos.Height / 2);
            Rectangle rectSlotLabelTriunfos = new Rectangle(rectSlotTriunfos.Left, rectSlotTriunfos.Top + rectSlotTriunfos.Height / 2, rectSlotTriunfos.Width, rectSlotTriunfos.Height / 2);
            Rectangle rectLabelTriunfosTítulo = ContraerRectángulo(rectSlotLabelTriunfosTítulo, 10, 10);
            Rectangle rectLabelTriunfos = ContraerRectángulo(rectSlotLabelTriunfos, 10, 10);

            // Slot de quién triunfa.
            Rectangle rectSlotQuiénTriunfa = rectSlots[1];
            Rectangle rectSlotLabelQuiénTriunfaTítulo = new Rectangle(rectSlotQuiénTriunfa.Left, rectSlotQuiénTriunfa.Top, rectSlotQuiénTriunfa.Width, rectSlotQuiénTriunfa.Height / 2);
            Rectangle rectSlotLabelQuiénTriunfa = new Rectangle(rectSlotQuiénTriunfa.Left, rectSlotQuiénTriunfa.Top + rectSlotQuiénTriunfa.Height / 2, rectSlotQuiénTriunfa.Width, rectSlotQuiénTriunfa.Height / 2);
            Rectangle rectLabelQuiénTriunfaTítulo = ContraerRectángulo(rectSlotLabelQuiénTriunfaTítulo, 10, 10);
            Rectangle rectLabelQuiénTriunfa = ContraerRectángulo(rectSlotLabelQuiénTriunfa, 10, 10);

            // Slot de próximo mano.
            Rectangle rectSlotPróximoMano = rectSlots[2];
            Rectangle rectSlotLabelPróximoManoTítulo = new Rectangle(rectSlotPróximoMano.Left, rectSlotPróximoMano.Top, rectSlotPróximoMano.Width, rectSlotPróximoMano.Height / 2);
            Rectangle rectSlotLabelPróximoMano = new Rectangle(rectSlotPróximoMano.Left, rectSlotPróximoMano.Top + rectSlotPróximoMano.Height / 2, rectSlotPróximoMano.Width, rectSlotPróximoMano.Height / 2);
            Rectangle rectLabelPróximoManoTítulo = ContraerRectángulo(rectSlotLabelPróximoManoTítulo, 10, 10);
            Rectangle rectLabelPróximoMano = ContraerRectángulo(rectSlotLabelPróximoMano, 10, 10);

            // Slot de se pidió.
            Rectangle rectSlotSePidió = rectSlots[3];
            Rectangle rectSlotLabelSePidióTítulo = new Rectangle(rectSlotSePidió.Left, rectSlotSePidió.Top, rectSlotSePidió.Width, rectSlotSePidió.Height / 2);
            Rectangle rectSlotSePidióCheckBoxes = new Rectangle(rectSlotSePidió.Left, rectSlotSePidió.Top + rectSlotSePidió.Height / 2, rectSlotSePidió.Width, rectSlotSePidió.Height / 2);
            Rectangle rectSlotCheckBoxSolo = new Rectangle(rectSlotSePidióCheckBoxes.Left, rectSlotSePidióCheckBoxes.Top, rectSlotSePidióCheckBoxes.Width / 3, rectSlotSePidióCheckBoxes.Height);
            Rectangle rectSlotCheckBoxCinco = new Rectangle(rectSlotSePidióCheckBoxes.Left + rectSlotSePidióCheckBoxes.Width / 3, rectSlotSePidióCheckBoxes.Top, rectSlotSePidióCheckBoxes.Width / 3, rectSlotSePidióCheckBoxes.Height);
            Rectangle rectSlotCheckBoxTodas = new Rectangle(rectSlotSePidióCheckBoxes.Left + rectSlotSePidióCheckBoxes.Width * 2 / 3, rectSlotSePidióCheckBoxes.Top, rectSlotSePidióCheckBoxes.Width / 3, rectSlotSePidióCheckBoxes.Height);
            Rectangle rectLabelSePidióTítulo = ContraerRectángulo(rectSlotLabelSePidióTítulo, 10, 10);
            Rectangle rectCheckBoxSolo = ContraerRectángulo(rectSlotCheckBoxSolo, 10, 10);
            Rectangle rectCheckBoxCinco = ContraerRectángulo(rectSlotCheckBoxCinco, 10, 10);
            Rectangle rectCheckBoxTodas = ContraerRectángulo(rectSlotCheckBoxTodas, 10, 10);

            // Slot del log.
            Rectangle rectSlotLog = rectSlots[4];
            Rectangle rectTextBoxLog = ContraerRectángulo(rectSlotLog, 10, 10);

            // Slot de los botones.
            Rectangle rectSlotBotones = rectSlots[5];
            Rectangle rectSlotBotónComenzar = new Rectangle(rectSlotBotones.Left, rectSlotBotones.Top, rectSlotBotones.Width / 2, rectSlotBotones.Height);
            Rectangle rectSlotBotónSalir = new Rectangle(rectSlotBotones.Left + rectSlotBotones.Width / 2, rectSlotBotones.Top, rectSlotBotones.Width / 2, rectSlotBotones.Height);
            Rectangle rectBotónComenzar = ContraerRectángulo(rectSlotBotónComenzar, 10, 30);
            Rectangle rectBotónSalir = ContraerRectángulo(rectSlotBotónSalir, 10, 30);

            // Selectores de abajo.
            Rectangle rectZonaAbajo = new Rectangle(0, rectMesa.Bottom, rectZonaJuego.Width, rectZonaJuego.Height - rectMesa.Bottom);
            Rectangle rectTodosSelectoresAbajo = ContraerRectángulo(rectZonaAbajo, 20, 10);
            Rectangle[] rectSelectoresAbajo = new Rectangle[8];
            int huecoEntreSelectores = (rectTodosSelectoresAbajo.Width * 10 / 100) / 7;
            Size tamañoSelectorAbajo = new Size((rectTodosSelectoresAbajo.Width - 7 * huecoEntreSelectores) / 8, rectTodosSelectoresAbajo.Height);
            for (int i = 0; i < rectSelectoresAbajo.Length; i++)
            {
                Point EsquinaIzquierdaSelector = new Point(rectTodosSelectoresAbajo.Left + i*(tamañoSelectorAbajo.Width + huecoEntreSelectores), rectTodosSelectoresAbajo.Top);
                rectSelectoresAbajo[i] = new Rectangle(EsquinaIzquierdaSelector.X, EsquinaIzquierdaSelector.Y, tamañoSelectorAbajo.Width, tamañoSelectorAbajo.Height);
            }

            // Selectores de la derecha.
            Rectangle rectZonaDerecha = new Rectangle(rectMesa.Right, 0, rectZonaJuego.Width - rectMesa.Right, rectZonaJuego.Height);
            Rectangle rectTodosSelectoresDerecha = ContraerRectángulo(rectZonaDerecha, 10, 20);
            Rectangle[] rectSelectoresDerecha = new Rectangle[8];
            Size tamañoSelectorDerecha = new Size(rectTodosSelectoresDerecha.Width, (rectTodosSelectoresDerecha.Height - 7 * huecoEntreSelectores) / 8);
            for (int i = 0; i < rectSelectoresDerecha.Length; i++)
            {
                Point EsquinaDerechaSelector = new Point(rectTodosSelectoresDerecha.Left, rectTodosSelectoresDerecha.Top + i * (tamañoSelectorDerecha.Height + huecoEntreSelectores));
                rectSelectoresDerecha[i] = new Rectangle(EsquinaDerechaSelector.X, EsquinaDerechaSelector.Y, tamañoSelectorDerecha.Width, tamañoSelectorDerecha.Height);
            }

            // Selectores de arriba.
            Rectangle rectZonaArriba = new Rectangle(0, 0, rectZonaJuego.Width, rectMesa.Top);
            Rectangle rectTodosSelectoresArriba = ContraerRectángulo(rectZonaArriba, 20, 10);
            Rectangle[] rectSelectoresArriba = new Rectangle[8];
            Size tamañoSelectorArriba = new Size((rectTodosSelectoresArriba.Width - 7 * huecoEntreSelectores) / 8, rectTodosSelectoresArriba.Height);
            for (int i = 0; i < rectSelectoresArriba.Length; i++)
            {
                Point EsquinaIzquierdaSelector = new Point(rectTodosSelectoresArriba.Left + i * (tamañoSelectorArriba.Width + huecoEntreSelectores), rectTodosSelectoresArriba.Top);
                rectSelectoresArriba[i] = new Rectangle(EsquinaIzquierdaSelector.X, EsquinaIzquierdaSelector.Y, tamañoSelectorArriba.Width, tamañoSelectorArriba.Height);
            }

            // Selectores de la izquierda.
            Rectangle rectZonaIzquierda = new Rectangle(0, 0, rectMesa.Left, rectZonaJuego.Height);
            Rectangle rectTodosSelectoresIzquierda = ContraerRectángulo(rectZonaIzquierda, 10, 20);
            Rectangle[] rectSelectoresIzquierda = new Rectangle[8];
            Size tamañoSelectorIzquierda = new Size(rectTodosSelectoresIzquierda.Width, (rectTodosSelectoresIzquierda.Height - 7 * huecoEntreSelectores) / 8);
            for (int i = 0; i < rectSelectoresIzquierda.Length; i++)
            {
                Point EsquinaIzquierdaSelector = new Point(rectTodosSelectoresIzquierda.Left, rectTodosSelectoresIzquierda.Top + i * (tamañoSelectorIzquierda.Height + huecoEntreSelectores));
                rectSelectoresIzquierda[i] = new Rectangle(EsquinaIzquierdaSelector.X, EsquinaIzquierdaSelector.Y, tamañoSelectorIzquierda.Width, tamañoSelectorIzquierda.Height);
            }

            // Botones juego de la izquierda.
            Rectangle rectBotonesJuegoIzquierda = new Rectangle(rectTodosSelectoresIzquierda.Left, rectTodosSelectoresAbajo.Top, 
                                                                rectTodosSelectoresAbajo.Left - 2 * rectTodosSelectoresIzquierda.Left, rectTodosSelectoresAbajo.Height);
            int huecoEntreBotonesJuego = rectBotonesJuegoIzquierda.Width * 10 / 100;
            Size tamañoBotonesJuego = new Size((rectBotonesJuegoIzquierda.Width - huecoEntreBotonesJuego) / 2, (rectBotonesJuegoIzquierda.Height - huecoEntreBotonesJuego) / 2);
            Rectangle rectBotónJuego = new Rectangle(rectBotonesJuegoIzquierda.Left, rectBotonesJuegoIzquierda.Top, tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);
            Rectangle rectBotónPaso = new Rectangle(rectBotonesJuegoIzquierda.Left + tamañoBotonesJuego.Width + huecoEntreBotonesJuego, rectBotonesJuegoIzquierda.Top,
                                                    tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);
            Rectangle rectBotónMeVoySolo = new Rectangle(rectBotonesJuegoIzquierda.Left, rectBotonesJuegoIzquierda.Top + tamañoBotonesJuego.Height + huecoEntreBotonesJuego,
                                                         tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);
            Rectangle rectBotónVayaSolo = new Rectangle(rectBotonesJuegoIzquierda.Left + tamañoBotonesJuego.Width + huecoEntreBotonesJuego, 
                                                        rectBotonesJuegoIzquierda.Top + tamañoBotonesJuego.Height + huecoEntreBotonesJuego,
                                                        tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);

            // Botones juego de la derecha.
            Rectangle rectBotonesJuegoDerecha = new Rectangle(rectTodosSelectoresAbajo.Right + (rectZonaJuego.Right - rectTodosSelectoresDerecha.Right),
                                                              rectTodosSelectoresAbajo.Top, rectBotonesJuegoIzquierda.Width, rectBotonesJuegoIzquierda.Height);
            Rectangle rectBotónVayaUsted = new Rectangle(rectBotonesJuegoDerecha.Left, rectBotonesJuegoDerecha.Top, tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);
            Rectangle rectBotónRechazoZanga = new Rectangle(rectBotonesJuegoDerecha.Left + tamañoBotonesJuego.Width + huecoEntreBotonesJuego, rectBotonesJuegoDerecha.Top,
                                                            tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);
            Rectangle rectBotónPidoCinco = new Rectangle(rectBotonesJuegoDerecha.Left, rectBotonesJuegoDerecha.Top + tamañoBotonesJuego.Height + huecoEntreBotonesJuego,
                                                         tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);
            Rectangle rectBotónPidoTodas = new Rectangle(rectBotonesJuegoDerecha.Left + tamañoBotonesJuego.Width + huecoEntreBotonesJuego,
                                                         rectBotonesJuegoDerecha.Top + tamañoBotonesJuego.Height + huecoEntreBotonesJuego,
                                                         tamañoBotonesJuego.Width, tamañoBotonesJuego.Height);

            // Botones de selección de palo.
            Rectangle rectBotónBastos = new Rectangle(rectBotonesJuegoIzquierda.Left, rectBotonesJuegoIzquierda.Top - huecoEntreBotonesJuego - tamañoBotonesJuego.Height,
                                                      (tamañoBotonesJuego.Width - huecoEntreBotonesJuego) / 2, tamañoBotonesJuego.Height);
            Rectangle rectBotónCopas = new Rectangle(rectBotonesJuegoIzquierda.Left + huecoEntreBotonesJuego + (tamañoBotonesJuego.Width - huecoEntreBotonesJuego) / 2, 
                                                     rectBotonesJuegoIzquierda.Top - huecoEntreBotonesJuego - tamañoBotonesJuego.Height,
                                                     (tamañoBotonesJuego.Width - huecoEntreBotonesJuego) / 2, tamañoBotonesJuego.Height);
            Rectangle rectBotónEspadas = new Rectangle(rectBotónRechazoZanga.Left, rectBotonesJuegoIzquierda.Top - huecoEntreBotonesJuego - tamañoBotonesJuego.Height,
                                                      (tamañoBotonesJuego.Width - huecoEntreBotonesJuego) / 2, tamañoBotonesJuego.Height);
            Rectangle rectBotónOros = new Rectangle(rectBotónRechazoZanga.Left + huecoEntreBotonesJuego + (tamañoBotonesJuego.Width - huecoEntreBotonesJuego) / 2, 
                                                    rectBotonesJuegoIzquierda.Top - huecoEntreBotonesJuego - tamañoBotonesJuego.Height,
                                                    (tamañoBotonesJuego.Width - huecoEntreBotonesJuego) / 2, tamañoBotonesJuego.Height);


            labelTriunfosTítulo = new Label(manager);
            labelTriunfosTítulo.Init();
            AsignarRectángulo(labelTriunfosTítulo, rectLabelTriunfosTítulo);
            labelTriunfosTítulo.Text = "Triunfos";

            labelTriunfos = new Label(manager);
            labelTriunfos.Init();
            AsignarRectángulo(labelTriunfos, rectLabelTriunfos);
            labelTriunfos.Text = "Palo que es triunfo";

            labelQuiénTriunfaTítulo = new Label(manager);
            labelQuiénTriunfaTítulo.Init();
            AsignarRectángulo(labelQuiénTriunfaTítulo, rectLabelQuiénTriunfaTítulo);
            labelQuiénTriunfaTítulo.Text = "Quién Triunfa";

            labelQuiénTriunfa = new Label(manager);
            labelQuiénTriunfa.Init();
            AsignarRectángulo(labelQuiénTriunfa, rectLabelQuiénTriunfa);
            labelQuiénTriunfa.Text = "Jugador que triunfa";

            labelPróximoManoTítulo = new Label(manager);
            labelPróximoManoTítulo.Init();
            AsignarRectángulo(labelPróximoManoTítulo, rectLabelPróximoManoTítulo);
            labelPróximoManoTítulo.Text = "Próximo mano";

            labelPróximoMano = new Label(manager);
            labelPróximoMano.Init();
            AsignarRectángulo(labelPróximoMano, rectLabelPróximoMano);
            labelPróximoMano.Text = "Jugador que es próximo mano";

            labelSePidióTítulo = new Label(manager);
            labelSePidióTítulo.Init();
            AsignarRectángulo(labelSePidióTítulo, rectLabelSePidióTítulo);
            labelSePidióTítulo.Text = "Se pidió...";

            checkBoxSolo = new CheckBox(manager);
            checkBoxSolo.Init();
            AsignarRectángulo(checkBoxSolo, rectCheckBoxSolo);
            checkBoxSolo.Text = "Solo";
            checkBoxSolo.Checked = false;
            checkBoxSolo.Passive = true;

            checkBoxCinco = new CheckBox(manager);
            checkBoxCinco.Init();
            AsignarRectángulo(checkBoxCinco, rectCheckBoxCinco);
            checkBoxCinco.Text = "Cinco";
            checkBoxCinco.Checked = false;
            checkBoxCinco.Passive = true;

            checkBoxTodas = new CheckBox(manager);
            checkBoxTodas.Init();
            AsignarRectángulo(checkBoxTodas, rectCheckBoxTodas);
            checkBoxTodas.Text = "Todas";
            checkBoxTodas.Checked = false;
            checkBoxTodas.Passive = true;

            textBoxLog = new TextBox(manager);
            textBoxLog.Init();
            AsignarRectángulo(textBoxLog, rectTextBoxLog);
            textBoxLog.Text = "Aquí saldrá el log";
            textBoxLog.ReadOnly = true;

            botónComenzar = new Button(manager);
            botónComenzar.Init();
            AsignarRectángulo(botónComenzar, rectBotónComenzar);
            botónComenzar.Text = "Comenzar";
            botónComenzar.MousePress += (object sender, MouseEventArgs e) => { checkBoxSolo.Checked = true; };

            botónSalir = new Button(manager);
            botónSalir.Init();
            AsignarRectángulo(botónSalir, rectBotónSalir);
            botónSalir.Text = "Salir";
            botónSalir.MousePress += handlerSalir;

            selectoresAbajo = new SelectorCarta[8];
            for (int i = 0; i < selectoresAbajo.Length; i++)
            {
                selectoresAbajo[i] = new SelectorCarta(manager, SelectorCarta.Orientación.Abajo);
                selectoresAbajo[i].Init();
                AsignarRectángulo(selectoresAbajo[i], rectSelectoresAbajo[i]);
                selectoresAbajo[i].AsignarCarta(new Carta(Valor.As, Palo.Copas));
            }

            selectoresDerecha = new SelectorCarta[8];
            for (int i = 0; i < selectoresDerecha.Length; i++)
            {
                selectoresDerecha[i] = new SelectorCarta(manager, SelectorCarta.Orientación.Derecha);
                selectoresDerecha[i].Init();
                AsignarRectángulo(selectoresDerecha[i], rectSelectoresDerecha[i]);
                selectoresDerecha[i].AsignarCarta(new Carta(Valor.As, Palo.Copas));
            }

            selectoresArriba = new SelectorCarta[8];
            for (int i = 0; i < selectoresArriba.Length; i++)
            {
                selectoresArriba[i] = new SelectorCarta(manager, SelectorCarta.Orientación.Arriba);
                selectoresArriba[i].Init();
                AsignarRectángulo(selectoresArriba[i], rectSelectoresArriba[i]);
                selectoresArriba[i].AsignarCarta(new Carta(Valor.As, Palo.Copas));
            }

            selectoresIzquierda = new SelectorCarta[8];
            for (int i = 0; i < selectoresIzquierda.Length; i++)
            {
                selectoresIzquierda[i] = new SelectorCarta(manager, SelectorCarta.Orientación.Izquierda);
                selectoresIzquierda[i].Init();
                AsignarRectángulo(selectoresIzquierda[i], rectSelectoresIzquierda[i]);
                selectoresIzquierda[i].AsignarCarta(new Carta(Valor.As, Palo.Copas));
            }

            botónJuego = new Button(manager);
            botónJuego.Init();
            AsignarRectángulo(botónJuego, rectBotónJuego);
            botónJuego.Text = "Juego";

            botónPaso = new Button(manager);
            botónPaso.Init();
            AsignarRectángulo(botónPaso, rectBotónPaso);
            botónPaso.Text = "Paso";

            botónMeVoySolo = new Button(manager);
            botónMeVoySolo.Init();
            AsignarRectángulo(botónMeVoySolo, rectBotónMeVoySolo);
            botónMeVoySolo.Text = "Me Voy Solo";

            botónVayaSolo = new Button(manager);
            botónVayaSolo.Init();
            AsignarRectángulo(botónVayaSolo, rectBotónVayaSolo);
            botónVayaSolo.Text = "Vaya Solo";

            botónVayaUsted = new Button(manager);
            botónVayaUsted.Init();
            AsignarRectángulo(botónVayaUsted, rectBotónVayaUsted);
            botónVayaUsted.Text = "Vaya Usted";

            botónRechazoZanga = new Button(manager);
            botónRechazoZanga.Init();
            AsignarRectángulo(botónRechazoZanga, rectBotónRechazoZanga);
            botónRechazoZanga.Text = "Rechazo Zanga";

            botónPidoCinco = new Button(manager);
            botónPidoCinco.Init();
            AsignarRectángulo(botónPidoCinco, rectBotónPidoCinco);
            botónPidoCinco.Text = "Pido Cinco";

            botónPidoTodas = new Button(manager);
            botónPidoTodas.Init();
            AsignarRectángulo(botónPidoTodas, rectBotónPidoTodas);
            botónPidoTodas.Text = "Pido Todas";

            botónBastos = new Button(manager);
            botónBastos.Init();
            AsignarRectángulo(botónBastos, rectBotónBastos);
            botónBastos.Text = "B";

            botónCopas = new Button(manager);
            botónCopas.Init();
            AsignarRectángulo(botónCopas, rectBotónCopas);
            botónCopas.Text = "C";

            botónEspadas = new Button(manager);
            botónEspadas.Init();
            AsignarRectángulo(botónEspadas, rectBotónEspadas);
            botónEspadas.Text = "E";

            botónOros = new Button(manager);
            botónOros.Init();
            AsignarRectángulo(botónOros, rectBotónOros);
            botónOros.Text = "O";

            panelZonaControl = new Panel(manager);
            panelZonaControl.Init();
            AsignarRectángulo(panelZonaControl, rectZonaControl);
            panelZonaControl.StayOnBack = true;
            panelZonaControl.Alpha = 50;
            panelZonaControl.BevelStyle = BevelStyle.Raised;
            panelZonaControl.Text = "Prueba";


            monitorMesa = new MonitorMesa(manager, tamañoSelectorAbajo);
            monitorMesa.Init();
            AsignarRectángulo(monitorMesa, rectMesa);
            monitorMesa.CalcularDistancias();
        }

        public override void Inicializar()
        {
            Manager.Add(monitorMesa);
            Manager.Add(labelTriunfosTítulo);
            Manager.Add(labelTriunfos);
            Manager.Add(labelQuiénTriunfaTítulo);
            Manager.Add(labelQuiénTriunfa);
            Manager.Add(labelPróximoManoTítulo);
            Manager.Add(labelPróximoMano);
            Manager.Add(labelSePidióTítulo);
            Manager.Add(checkBoxSolo);
            Manager.Add(checkBoxCinco);
            Manager.Add(checkBoxTodas);
            Manager.Add(textBoxLog);
            Manager.Add(botónComenzar);
            Manager.Add(botónSalir);
            for (int i = 0; i < selectoresAbajo.Length; i++)
            {
                Manager.Add(selectoresAbajo[i]);
            }
            for (int i = 0; i < selectoresDerecha.Length; i++)
            {
                Manager.Add(selectoresDerecha[i]);
            }
            for (int i = 0; i < selectoresArriba.Length; i++)
            {
                Manager.Add(selectoresArriba[i]);
            }
            for (int i = 0; i < selectoresIzquierda.Length; i++)
            {
                Manager.Add(selectoresIzquierda[i]);
            }
            Manager.Add(botónJuego);
            Manager.Add(botónPaso);
            Manager.Add(botónMeVoySolo);
            Manager.Add(botónVayaSolo);
            Manager.Add(botónVayaUsted);
            Manager.Add(botónRechazoZanga);
            Manager.Add(botónPidoCinco);
            Manager.Add(botónPidoTodas);
            Manager.Add(botónBastos);
            Manager.Add(botónCopas);
            Manager.Add(botónEspadas);
            Manager.Add(botónOros);
            Manager.Add(panelZonaControl);
        }

        public override void Finalizar()
        {
            Manager.Remove(monitorMesa);
            Manager.Remove(labelTriunfosTítulo);
            Manager.Remove(labelTriunfos);
            Manager.Remove(labelQuiénTriunfaTítulo);
            Manager.Remove(labelQuiénTriunfa);
            Manager.Remove(labelPróximoManoTítulo);
            Manager.Remove(labelPróximoMano);
            Manager.Remove(labelSePidióTítulo);
            Manager.Remove(checkBoxSolo);
            Manager.Remove(checkBoxCinco);
            Manager.Remove(checkBoxTodas);
            Manager.Remove(textBoxLog);
            Manager.Remove(botónComenzar);
            Manager.Remove(botónSalir);
            for (int i = 0; i < selectoresAbajo.Length; i++)
            {
                Manager.Remove(selectoresAbajo[i]);
            }
            for (int i = 0; i < selectoresDerecha.Length; i++)
            {
                Manager.Remove(selectoresDerecha[i]);
            }
            for (int i = 0; i < selectoresArriba.Length; i++)
            {
                Manager.Remove(selectoresArriba[i]);
            }
            for (int i = 0; i < selectoresIzquierda.Length; i++)
            {
                Manager.Remove(selectoresIzquierda[i]);
            }
            Manager.Remove(botónJuego);
            Manager.Remove(botónPaso);
            Manager.Remove(botónMeVoySolo);
            Manager.Remove(botónVayaSolo);
            Manager.Remove(botónVayaUsted);
            Manager.Remove(botónRechazoZanga);
            Manager.Remove(botónPidoCinco);
            Manager.Remove(botónPidoTodas);
            Manager.Remove(botónBastos);
            Manager.Remove(botónCopas);
            Manager.Remove(botónEspadas);
            Manager.Remove(botónOros);
        }

        private void AsignarRectángulo(Control control, Rectangle rect)
        {
            control.Left = rect.Left;
            control.Top = rect.Top;
            control.Width = rect.Width;
            control.Height = rect.Height;
        }

        private Rectangle ContraerRectángulo(Rectangle rect, int contHorizontal, int contVertical)
        {
            Rectangle rectContraído = rect;
            rectContraído.Inflate(-rectContraído.Width * contHorizontal / 100, -rectContraído.Height * contVertical / 100);
            return rectContraído;
        }
    }
}

