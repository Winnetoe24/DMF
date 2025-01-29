package de.smart.city.communication;

import de.smart.city.infrastructure.Asset;
import java.util.Objects;

public class NetworkNode extends Asset {
    protected static NetworkNodeDelegate delegate;
    protected NetworkType type;
    protected Bandwidth bandwidth;
    protected int connectedDevices;
    protected double uptime;
    protected boolean isRedundant;



    public NetworkType getType() {
        return this.type;
    }

    public void setType(NetworkType type) {
        this.type = type;
    }

    public Bandwidth getBandwidth() {
        return this.bandwidth;
    }

    public void setBandwidth(Bandwidth bandwidth) {
        this.bandwidth = bandwidth;
    }

    public int getConnectedDevices() {
        return this.connectedDevices;
    }

    public void setConnectedDevices(int connectedDevices) {
        this.connectedDevices = connectedDevices;
    }

    public double getUptime() {
        return this.uptime;
    }

    public void setUptime(double uptime) {
        this.uptime = uptime;
    }

    public boolean getIsRedundant() {
        return this.isRedundant;
    }

    public void setIsRedundant(boolean isRedundant) {
        this.isRedundant = isRedundant;
    }


    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        NetworkNode entity = (NetworkNode) o;
        return Objects.equals(assetId, entity.assetId) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(assetId);
    }
}