using System;
using System.Threading;

namespace Restaurant
{
	class Program
	{
		public static void Mesero(int no, int chefs)
		{

			Console.WriteLine("Mesero recibiendo Orden {0}...\n" +
				"\n (⌐■_■) ____" +
				"\n      \\/___/" +
				"\n        ", no);
			System.Threading.Thread.Sleep(1);
			Random CSC = new Random();

			int ordenTomada = CSC.Next(1, 12);

			string ordenEscrita = "";

			switch (ordenTomada)
			{
				case 1:

					ordenEscrita = "Pechuga con Papas";

					break;

				case 2:

					ordenEscrita = "Pierna con Papas";

					break;
				case 3:

					ordenEscrita = "Ala con Papas";

					break;

				case 4:

					ordenEscrita = "Hamburguesa de Pollo con Papas";

					break;

				case 5:

					ordenEscrita = "Hamburguesa con Papas";

					break;
				case 6:

					ordenEscrita = "Boneless con salsa bufalo y Papas";

					break;

				case 7:

					ordenEscrita = "Boneless con salsa barbacoa y Papas";

					break;
				case 8:

					ordenEscrita = "Sandwich de pollo a la planca con Papas";

					break;
				case 9:

					ordenEscrita = "Orden de Carne Asada con Tajadas";

					break;
				case 10:

					ordenEscrita = "Combo Familiar";

					break;
				case 11:

					ordenEscrita = "Combo para niño";

					break;

				case 12:

					ordenEscrita = "Combo para estudiantes";

					break;

				default:
					ordenEscrita = "Combo secreto";

					break;

			}

			Console.WriteLine("Gracias por su pedido, usted es el numero {0}",no);

			Chef(ordenEscrita,chefs,no);

			Console.WriteLine("\nMesero le da el pedido al cliente numero {0}: {1}" +
				"\n\n          /¯¯¯¯\\" +
				"\n b(⌐■_■)__\\____/ \n", no, ordenEscrita);

		}

		public static void Chef(string orden,int chef,int no)
		{
			string nombre = "";
			switch (chef)
			{
				case 1:
					nombre = "Kobaski";
					break;
				case 2:
					nombre = "Patricia";
					break;
			}

			Console.WriteLine("{1} Recibe el pedido {2}: {0}", orden,nombre,no);

			Console.WriteLine("{1} prepara: {0}", orden,nombre);


			System.Threading.Thread.Sleep(100);

			switch (chef)
			{
				case 1:
					Console.WriteLine("\n{0} Cocinando orden numero:{1} ..." +
				"\n       .--,--." +
				"\n       `.  ,.'" +
				"\n        |___|" +
				"\n        :o o:   O" +
				"\n       _`~^~'_  |" +
				"\n     /'   ^   `| =)\n", nombre,no);
					break;
				case 2:
					Console.WriteLine("\n{0} Cocinando orden numero: {1}..." +
				"\n       .--,--." +
				"\n       `.  ,.'" +
				"\n        |___|" +
				"\n      //:o o:\\\\ O" +
				"\n    // _` W '_\\\\|" +
				"\n     /'   ^   `| =)\n", nombre,no);
					break;
			}

			
			System.Threading.Thread.Sleep(100);
			Console.WriteLine("{1} Grita: {0} del cliente numero {2}!!!", orden,nombre,no);


		}




		static void Main(string[] args)
		{

			
			int f = 0;
			for (int i = 1; i < 100; i++)
			{
				
				if (i % 2 == 0)
				{
					Thread cola = new Thread(() => Mesero(i,1));
					cola.Start();
				}
				else
				{
					Thread cola2 = new Thread(() => Mesero(i,2));
					cola2.Start();
				}

				Thread.Sleep(100);


			}


		}
	}
}
