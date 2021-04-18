namespace PRACTICA_9_IMAGELIST_LISTVIEW
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rdLargeIcon = new System.Windows.Forms.RadioButton();
            this.rdSmallIcon = new System.Windows.Forms.RadioButton();
            this.rdLista = new System.Windows.Forms.RadioButton();
            this.rdDetalle = new System.Windows.Forms.RadioButton();
            this.rdTitulo = new System.Windows.Forms.RadioButton();
            this.listView1 = new System.Windows.Forms.ListView();
            this.label1 = new System.Windows.Forms.Label();
            this.imageListSmall = new System.Windows.Forms.ImageList(this.components);
            this.imageListLarge = new System.Windows.Forms.ImageList(this.components);
            this.btnAtras = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rdTitulo);
            this.groupBox1.Controls.Add(this.rdDetalle);
            this.groupBox1.Controls.Add(this.rdLista);
            this.groupBox1.Controls.Add(this.rdSmallIcon);
            this.groupBox1.Controls.Add(this.rdLargeIcon);
            this.groupBox1.Location = new System.Drawing.Point(433, 35);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(119, 360);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Modo de Vista";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // rdLargeIcon
            // 
            this.rdLargeIcon.AutoSize = true;
            this.rdLargeIcon.Location = new System.Drawing.Point(18, 26);
            this.rdLargeIcon.Name = "rdLargeIcon";
            this.rdLargeIcon.Size = new System.Drawing.Size(73, 17);
            this.rdLargeIcon.TabIndex = 0;
            this.rdLargeIcon.Text = "LargeIcon";
            this.rdLargeIcon.UseVisualStyleBackColor = true;
            this.rdLargeIcon.CheckedChanged += new System.EventHandler(this.rdLargeIcon_CheckedChanged);
            // 
            // rdSmallIcon
            // 
            this.rdSmallIcon.AutoSize = true;
            this.rdSmallIcon.Location = new System.Drawing.Point(18, 65);
            this.rdSmallIcon.Name = "rdSmallIcon";
            this.rdSmallIcon.Size = new System.Drawing.Size(71, 17);
            this.rdSmallIcon.TabIndex = 1;
            this.rdSmallIcon.Text = "SmallIcon";
            this.rdSmallIcon.UseVisualStyleBackColor = true;
            this.rdSmallIcon.CheckedChanged += new System.EventHandler(this.rdSmallIcon_CheckedChanged);
            // 
            // rdLista
            // 
            this.rdLista.AutoSize = true;
            this.rdLista.Location = new System.Drawing.Point(18, 115);
            this.rdLista.Name = "rdLista";
            this.rdLista.Size = new System.Drawing.Size(47, 17);
            this.rdLista.TabIndex = 2;
            this.rdLista.Text = "Lista";
            this.rdLista.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.rdLista.UseVisualStyleBackColor = true;
            this.rdLista.CheckedChanged += new System.EventHandler(this.rdLista_CheckedChanged);
            // 
            // rdDetalle
            // 
            this.rdDetalle.AutoSize = true;
            this.rdDetalle.Checked = true;
            this.rdDetalle.Location = new System.Drawing.Point(18, 160);
            this.rdDetalle.Name = "rdDetalle";
            this.rdDetalle.Size = new System.Drawing.Size(58, 17);
            this.rdDetalle.TabIndex = 3;
            this.rdDetalle.TabStop = true;
            this.rdDetalle.Text = "Detalle";
            this.rdDetalle.UseVisualStyleBackColor = true;
            this.rdDetalle.CheckedChanged += new System.EventHandler(this.rdDetalle_CheckedChanged);
            // 
            // rdTitulo
            // 
            this.rdTitulo.AutoSize = true;
            this.rdTitulo.Location = new System.Drawing.Point(18, 210);
            this.rdTitulo.Name = "rdTitulo";
            this.rdTitulo.Size = new System.Drawing.Size(51, 17);
            this.rdTitulo.TabIndex = 4;
            this.rdTitulo.Text = "Titulo";
            this.rdTitulo.UseVisualStyleBackColor = true;
            this.rdTitulo.CheckedChanged += new System.EventHandler(this.rdTitulo_CheckedChanged);
            // 
            // listView1
            // 
            this.listView1.HideSelection = false;
            this.listView1.LargeImageList = this.imageListLarge;
            this.listView1.Location = new System.Drawing.Point(10, 35);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(387, 360);
            this.listView1.SmallImageList = this.imageListSmall;
            this.listView1.TabIndex = 1;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.ItemActivate += new System.EventHandler(this.lvCarpetas_ItemActivate);
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(12, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(385, 22);
            this.label1.TabIndex = 2;
            // 
            // imageListSmall
            // 
            this.imageListSmall.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListSmall.ImageStream")));
            this.imageListSmall.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListSmall.Images.SetKeyName(0, "addressbook.ico");
            this.imageListSmall.Images.SetKeyName(1, "documents.ico");
            // 
            // imageListLarge
            // 
            this.imageListLarge.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListLarge.ImageStream")));
            this.imageListLarge.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListLarge.Images.SetKeyName(0, "addressbook.ico");
            this.imageListLarge.Images.SetKeyName(1, "documents.ico");
            // 
            // btnAtras
            // 
            this.btnAtras.Location = new System.Drawing.Point(236, 401);
            this.btnAtras.Name = "btnAtras";
            this.btnAtras.Size = new System.Drawing.Size(75, 23);
            this.btnAtras.TabIndex = 3;
            this.btnAtras.Text = "Atras";
            this.btnAtras.UseVisualStyleBackColor = true;
            this.btnAtras.Click += new System.EventHandler(this.btnAtras_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(586, 425);
            this.Controls.Add(this.btnAtras);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rdTitulo;
        private System.Windows.Forms.RadioButton rdDetalle;
        private System.Windows.Forms.RadioButton rdLista;
        private System.Windows.Forms.RadioButton rdSmallIcon;
        private System.Windows.Forms.RadioButton rdLargeIcon;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ImageList imageListSmall;
        private System.Windows.Forms.ImageList imageListLarge;
        private System.Windows.Forms.Button btnAtras;
    }
}

