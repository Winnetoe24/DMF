
let m: Map<string, string> = new Map<string, string>();

export enum MaintenancePriority {
    EMERGENCY = 'EMERGENCY',
    HIGH = 'HIGH',
    MEDIUM = 'MEDIUM',
    LOW = 'LOW'
}

export interface MaintenancePriorityDetails {
    level: number;
    description: string;
}

export const MaintenancePriorityInfo: Record<MaintenancePriority, MaintenancePriorityDetails> = {
    [MaintenancePriority.EMERGENCY]: { level: 1, description: "Immediate action required" },
    [MaintenancePriority.HIGH]: { level: 2, description: "Address within 24 hours" },
    [MaintenancePriority.MEDIUM]: { level: 3, description: "Address within 1 week" },
    [MaintenancePriority.LOW]: { level: 4, description: "Schedule during routine maintenance" }
};