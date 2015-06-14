using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using TomShane.Neoforce.Controls;

namespace Zanga
{
    public class JuegoZanga : Game
    {
        private GraphicsDeviceManager graphics;


        private Manager manager;
        //private Window window;
        private Button button;
        private TextBox textBox;
        private ComboBox comboBox;

        public JuegoZanga()
        {
            graphics = new GraphicsDeviceManager(this);

            // Basic setup of the game window.
            IsMouseVisible = true;
            IsFixedTimeStep = false;
            graphics.PreferredBackBufferWidth = 800;
            graphics.PreferredBackBufferHeight = 600;
            graphics.SynchronizeWithVerticalRetrace = false;

            // Create an instance of manager using Default skin. We set the fourth parameter to true,
            // so the instance of manager is registered as an XNA game component and methods
            // like Initialize(), Update() and Draw() are called automatically in the game loop.
            // If you set this parameter to false, you have to call Manager.Initialize(), 
            // Manager.Update() and Manager.Draw() manually in their respective overriden methods
            // of the game class.
            // If you use two-parameter constructor, Default skin is used and manager is registered.
            manager = new Manager(this, graphics, "Default", true);

            // Setting up the shared skins directory
            manager.SkinDirectory = @"..\..\Skins\";
        }

        protected override void Initialize()
        {
            base.Initialize();


            // If you have specified register parameter for the Manager to false put
            // manager.Initialize() method here.                   

            // Controls always have to be created and initialized after Manager.Initialize() is called.            

            // Create and setup Window control.
            //window = new Window(manager);
            //window.Init();
            //window.Text = "Getting Started";
            //window.Width = 480;
            //window.Height = 200;
            //window.Center();
            //window.Visible = true;

            // Create Button control and set the previous window as its parent.
            button = new Button(manager);
            button.Init();
            button.Text = "OK";
            button.Width = 72;
            button.Height = 24;
            button.Left = 0;// (window.ClientWidth / 2) - (button.Width / 2);
            button.Top = 0;//window.ClientHeight - button.Height - 8;
            button.Anchor = Anchors.Bottom;
            button.Click += aaa;
            //button.Parent = window.Parent;

            textBox = new TextBox(manager);
            textBox.Init();
            textBox.Left = 80;
            textBox.Top = 0;
            //comboBox.Items.Add("prueba");
            //comboBox.Items.Add("prueba2");
            textBox.Text = "aaaa";

            comboBox = new ComboBox(manager);
            comboBox.Init();
            //cmbMain.Parent = pnlControls;
            comboBox.Left = 16;
            comboBox.Top = 44;
            comboBox.Width = 64;
            comboBox.Height = 20;
            //cmbMain.ReadOnly = true;      
            comboBox.Anchor = Anchors.Left | Anchors.Top | Anchors.Right;
            comboBox.Items.Add("tururu");
            comboBox.ItemIndex = 0;
            comboBox.MaxItems = 5;
            //cmbMain.ToolTipType = typeof(ToolTip); 
            comboBox.ToolTip.Color = Color.Yellow; 

            // Add the window control to the manager processing queue.
            manager.Add(button);
            manager.Add(textBox);
            manager.Add(comboBox);
        }

        public void aaa(object sender, MouseEventArgs e)
        {
            button.Left += 20;
        }

        protected override void Update(GameTime gameTime)
        {
            base.Update(gameTime);

            // If you have specified "register" parameter for the Manager to false put
            // manager.Update(gameTime) method here.                  
        }

        protected override void Draw(GameTime gameTime)
        {
            graphics.GraphicsDevice.Clear(Color.White);
            base.Draw(gameTime);

            // If you have specified "register" parameter for the Manager to false put
            // manager.Draw(gameTime) method here to ensure the GUI is drawn at the 
            // top of all other stuff.                   
        }

    }
}
