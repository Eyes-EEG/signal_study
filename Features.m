classdef Features
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % This class computed the features table %
    % to train                               %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    properties
        matriz_alfa;
    end
    
    methods
        function obj = Features()
        end
        
        function [obj, featTable] = generateModelFeatures (obj,Datos_filtrados)

            canal1 = obj.CalculaValorAlfa(CH1);
            obj.matriz_alfa(length(obj.matriz_alfa)+1).canal1 = canal1;
       
        end
        
       
        function canal1 = CalculaValorAlfa (obj,CH1)
                sampling_rate = 125;
                nfft = DataFilter.get_nearest_power_of_two(sampling_rate);
                original_data = CH1;
                detrended = DataFilter.detrend(original_data, int32(DetrendOperations.LINEAR));
                [ampls, freqs] = DataFilter.get_psd_welch(detrended, nfft, nfft / 2, sampling_rate, int32(WindowFunctions.HANNING));
                canal1 = DataFilter.get_band_power(ampls, freqs, 7.0, 13.0);
        end
    end
end