Data = obj.features.matriz_alfa(1,45);
 
 Alpha_values = [Data.canal1 Data.canal2 Data.canal3  Data.canal4  Data.canal5  Data.canal6  Data.canal7  Data.canal8  Data.canal9  Data.canal10  Data.canal11  Data.canal12  Data.canal13 Data.canal14  Data.canal15  Data.canal16 ]; 

 figure1 = plot_topography({'Fp1','Fp2', 'F3', 'F4', 'Fz', 'C3', 'C4', 'Cz', 'T7', 'T8', 'P3', 'P4', 'Pz', 'O1', 'O2','Oz'}, Alpha_values);
