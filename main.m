
listaFicheros = {'1_close_left_eye_1.csv', '1_close_left_eye_2.csv', '1_close_left_eye_3.csv','1_close_left_eye_4.csv', '1_close_eyes_1.csv', '1_close_eyes_2.csv','1_close_eyes_3.csv', '1_close_eyes_4.csv', '1_close_right_eye_1.csv', '1_close_right_eye_2.csv', '1_close_right_eye_3.csv', '1_close_right_eye_4.csv','1_close_left_eye_1.csv', '1_close_left_eye_2.csv', '1_close_left_eye_3.csv','1_close_left_eye_4.csv'};

markers = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};

myDataset = Dataset();
obj.Features = Features();

 for i = 1 : length(markers)
     myDataset = myDataset.addTrial(listaFicheros{i}, markers{i})   
 end
Datos_filtrados = {myDataset.data_filtered(1:160).filtered_data};

Label = [ones(1,40) (repmat (2,1,40)) (repmat (3,1,40)) (repmat (4,1,40))];
  for i = 1 : 160
       [obj.features, featTable] = obj.features.generateModelFeatures (Datos_filtrados{i}, Label(i));   
  end
