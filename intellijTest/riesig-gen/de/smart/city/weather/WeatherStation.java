package de.smart.city.weather;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class WeatherStation extends Asset {
    protected static WeatherStationDelegate delegate;
    protected double temperature;
    protected double humidity;
    protected double windSpeed;
    protected double precipitation;
    protected WeatherCondition condition;



    public double getTemperature() {
        return this.temperature;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    public double getHumidity() {
        return this.humidity;
    }

    public void setHumidity(double humidity) {
        this.humidity = humidity;
    }

    public double getWindSpeed() {
        return this.windSpeed;
    }

    public void setWindSpeed(double windSpeed) {
        this.windSpeed = windSpeed;
    }

    public double getPrecipitation() {
        return this.precipitation;
    }

    public void setPrecipitation(double precipitation) {
        this.precipitation = precipitation;
    }

    public WeatherCondition getCondition() {
        return this.condition;
    }

    public void setCondition(WeatherCondition condition) {
        this.condition = condition;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        WeatherStation entity = (WeatherStation) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}