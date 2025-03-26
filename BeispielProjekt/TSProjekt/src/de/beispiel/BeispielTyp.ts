

export enum BeispielTyp {
    CODE = 0,
    TEXT = 1
}

export interface BeispielTypDetails {

}


export const BeispielTypInfo : Record<BeispielTyp, BeispielTypDetails> = {
    [BeispielTyp.CODE]: {  },
    [BeispielTyp.TEXT]: {  },

}

