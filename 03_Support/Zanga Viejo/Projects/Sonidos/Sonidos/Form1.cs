using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace Sonidos
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.InitialDirectory = textBox1.Text;
            openFileDialog1.Filter = "wav files (*.wav)|*.wav|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.Text = openFileDialog1.FileName;
            }
        }

        private Thread hiloSonidos;

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = false;
            textBox2.Enabled = false;
            textBox3.Enabled = false;
            button1.Enabled = false;
            button2.Enabled = false;
            button3.Enabled = true;
            ThreadStart myThreadDelegate = new ThreadStart(this.mainHiloSonidos);
			hiloSonidos = new Thread(myThreadDelegate);
			hiloSonidos.IsBackground = true;
            hiloSonidos.Start();
        }

        private void mainHiloSonidos()
        {
            System.Media.SoundPlayer sonido = new System.Media.SoundPlayer(textBox1.Text);
            Int16 veces = System.Convert.ToInt16(textBox2.Text);
            Int16 minutos = System.Convert.ToInt16(textBox3.Text);
            System.Random generadorAleatorio = new Random(System.DateTime.Now.Millisecond);
            Int16 contador;
            Int16[] instantes = new Int16[veces];
            while (true)
            {
                contador = 0;
                for (int i = 0; i < instantes.Length; i++)
                {
                    instantes[i] = (Int16)generadorAleatorio.Next(60 * minutos);
                }
                Array.Sort(instantes);
                for (int i = 0; i < 60 * minutos; i++)
                {
                    if (contador < instantes.Length && instantes[contador] == i)
                    {
                        sonido.Play();
                        contador++;
                    }
                    Thread.Sleep(1000);
                }
            }			
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (hiloSonidos.IsAlive)
                hiloSonidos.Abort();
            textBox1.Enabled = true;
            textBox2.Enabled = true;
            textBox3.Enabled = true;
            button1.Enabled = true;
            button2.Enabled = true;
            button3.Enabled = false;
        }
    }
}