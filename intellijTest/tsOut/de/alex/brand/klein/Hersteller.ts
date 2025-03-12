

/**
 * asd
**/
export enum Hersteller {
    NEIN = 0,
    JA = 1
}

export interface HerstellerDetails {
    name: string;
    id: number;
    da: Date;
}


export const HerstellerInfo : Record<Hersteller, HerstellerDetails> = {
    [Hersteller.NEIN]: { name: "sad", id: 2, da: new Date('2020-12-23T00:00:00Z') },
    [Hersteller.JA]: { name: "asdad", id: 1, da: new Date('2020-12-23T00:00:00Z') },

}

